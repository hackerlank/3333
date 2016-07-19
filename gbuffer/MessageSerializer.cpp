#include <set>
#include "google/protobuf/descriptor.h"
#include "google/protobuf/io/zero_copy_stream_impl_lite.h"
#include "bwsdk/Bwsdk.h"
#include "bwsdk/bSocket.h"

#include "platcommon/nullcommand.pb.h"

#include "MessageSerializer.h"

namespace
{
	/// @brief 解析namespace.type
	/// @return namespace
	std::string GetNamespace(const google::protobuf::Descriptor* descriptor)
	{
		if(descriptor == NULL)
			return std::string();
		if(descriptor->containing_type() == NULL)
			return descriptor->full_name().substr(0,
				descriptor->full_name().size() - descriptor->name().size() - 1);
		return GetNamespace(descriptor->containing_type());
	}
}

namespace gbuffer {
	//google::protobuf::io::CodedOutputStream::StaticVarintSize32<1> StaticVarintSize32_1;
	//CodedOutputStream::VarintSize32(1)
	
	int VarintSize32(unsigned int value)
	{
		return google::protobuf::io::CodedOutputStream::VarintSize32(google::protobuf::uint32(value));
	}

	using namespace google::protobuf;

	MessageSerializer::MessageSerializer()
	{
		bzero(m_unserializeTable,sizeof(m_unserializeTable));
		bzero(m_HandleInCPP,sizeof(m_HandleInCPP));
		m_DispatchToLua = false;
	}
	int MessageSerializer::GetMessageCmd(const google::protobuf::Message* message) const
	{
		serialize_table::const_iterator it = m_serializeTable.find(message->GetDescriptor());
		if(it == m_serializeTable.end())
		{
			Bwsdk::logger->error("MessageSerializer::Serialize err:%s",message->GetTypeName().c_str());
			return -1;
		}
		return it->second>>8;
	}
	int MessageSerializer::GetMessageParam(const google::protobuf::Message* message) const
	{
		serialize_table::const_iterator it = m_serializeTable.find(message->GetDescriptor());
		if(it == m_serializeTable.end())
		{
			Bwsdk::logger->error("MessageSerializer::Serialize err:%s",message->GetTypeName().c_str());
			return -1;
		}
		return it->second&0X000000FF;
	}
	int MessageSerializer::Serialize(const Message* message, io::CodedOutputStream* output,bool needlen) const
	{
		const int pos = output->ByteCount();
		serialize_table::const_iterator it = m_serializeTable.find(message->GetDescriptor());
		if(it == m_serializeTable.end())
		{
			Bwsdk::logger->error("MessageSerializer::Serialize err:%s",message->GetTypeName().c_str());
			return -1;
		}
		Pmd::ForwardNullUserPmd_CS send;
		send.set_bycmd(it->second>>8);
		send.set_byparam(it->second&0X000000FF);
		google::protobuf::uint8 msgdata[message->ByteSize()+32];
		//Bwsdk::logger->debug("MessageSerializer::Serialize:[%d,%d]",send.bycmd(),send.byparam());
		if(message->SerializeToArray(msgdata, sizeof(msgdata)) == false)
		{
			Bwsdk::logger->error("message->SerializeToArray err:%s",message->GetTypeName().c_str());
			return -1;
		}
		int msglen = message->ByteSize();
		if(msglen > 0)
		{
			send.set_data(msgdata,msglen);
		}
		//if(send.has_data())
		//{
		//}
		//Bwsdk::logger->debug("MessageSerializer::Serialize alllen:%d,%d,%d,%d",alllen, send.ByteSize() , msglen,send.data().size());
		//SerializeToOstream
		//SerializeToCodedStream
		if(needlen)
		{
			int alllen = send.ByteSize();// + msglen;
			output->WriteVarint32(google::protobuf::uint32(alllen));
		}
		if(send.SerializeToCodedStream(output) == false)// || message.SerializeToCodedStream(output) == false)
		{
			Bwsdk::logger->error("send.SerializeToCodedStream err:%s",message->GetTypeName().c_str());
			return -1;
		}
		return output->ByteCount() - pos;
	}
	

	int MessageSerializer::SerializeNmd(const Pmd::ForwardNullUserPmd_CS *nmd, void* bufOUT, size_t bufSize,bool needlen) const
	{
		google::protobuf::io::ArrayOutputStream stream(bufOUT, bufSize);
		google::protobuf::io::CodedOutputStream output(&stream);
		const int pos = output.ByteCount();
		if(needlen)
		{
			int alllen = nmd->ByteSize();// + msglen;
			output.WriteVarint32(google::protobuf::uint32(alllen));
		}
		if(nmd->SerializeToCodedStream(&output) == false)// || message.SerializeToCodedStream(output) == false)
		{
			Bwsdk::logger->error("SerializeNmd err:");
			return -1;
		}
		return output.ByteCount() - pos;
	}
	int MessageSerializer::Serialize(const google::protobuf::Message* message, void* bufOUT, size_t bufSize,bool needlen) const
	{
		google::protobuf::io::ArrayOutputStream stream(bufOUT, bufSize);
		google::protobuf::io::CodedOutputStream coded(&stream);
		return Serialize(message, &coded,needlen);
	}

	int MessageSerializer::SerializeMessageSize(int msglen, void* bufOUT, size_t bufSize) const
	{
		google::protobuf::io::ArrayOutputStream stream(bufOUT, bufSize);
		google::protobuf::io::CodedOutputStream output(&stream);
		const int pos = output.ByteCount();
		output.WriteVarint32(google::protobuf::uint32(msglen));
		return output.ByteCount() - pos;
	}

	Message* MessageSerializer::Deserialize(io::CodedInputStream* input,Pmd::ForwardNullUserPmd_CS *nmdout) const
	{
		// 解析消息类型
		if(nmdout->ParseFromCodedStream(input) == false)
		{
			Bwsdk::logger->error("MessageSerializer::Deserialize decode ForwardNullUserPmd_CS err");
			return NULL;
		}
		//Bwsdk::logger->debug("MessageSerializer::Deserialize decode ForwardNullUserPmd_CS:%d,%d",nmdout->bycmd(),nmdout->byparam());
		if(nmdout->has_data())
		{
			if(nmdout->bitmask() & Pmd::Bitmask_Compress)
			{
				size_t data_len = unzip_size(nmdout->data().size());
				unsigned char data[data_len];

				int retcode = uncompress_zebra(data, &data_len, (const Bytef*)nmdout->data().c_str(), nmdout->data().size());
				switch(retcode)
				{
					case Z_OK:
						//返回得到的字节数
						break;
					case Z_MEM_ERROR:
						Bwsdk::logger->fatal("(%s,%d,%d)Z_MEM_ERROR." ,nmdout->GetTypeName().c_str(),nmdout->bycmd(),nmdout->byparam());
						break;
					case Z_BUF_ERROR:
						Bwsdk::logger->fatal("(%s,%d,%d)Z_BUF_ERROR." ,nmdout->GetTypeName().c_str(),nmdout->bycmd(),nmdout->byparam());
						break;
					case Z_DATA_ERROR:
						Bwsdk::logger->fatal("(%s,%d,%d)Z_DATA_ERROR." ,nmdout->GetTypeName().c_str(),nmdout->bycmd(),nmdout->byparam());
						break;
				}
				nmdout->set_data(data,data_len);
				nmdout->set_bitmask(nmdout->bitmask() & (~Pmd::Bitmask_Compress));
			}
		}
		// 由消息类型得到构造器
		//判断消息是否在c++中handle 如果true使用c++中反序列化结构 否则使用lua中的反序列化结构
		unsigned int uMsgID = (nmdout->bycmd() << 8) + nmdout->byparam();
		int nType = (m_HandleInCPP[uMsgID] or !m_DispatchToLua) ? 0 : 1;

		const google::protobuf::Message *prototype = m_unserializeTable[nType][uMsgID];
		if(prototype == NULL)
		{
			Bwsdk::logger->error("MessageSerializer::Deserialize find err:[%d,%d] nType: %d",nmdout->bycmd(),nmdout->byparam(), nType);
			return NULL;
		}
		// 构造对应的消息并解析
		Message* message = prototype->New();
		//assert(message->GetTypeName() == prototype->GetTypeName());
		if(message->ParseFromArray(nmdout->data().c_str(),nmdout->data().size()) == false)
		{
			Bwsdk::logger->error("MessageSerializer::Deserialize decode err:[%d,%d],%s",nmdout->bycmd(),nmdout->byparam(),message->GetTypeName().c_str());
			delete message;
			return NULL;
		}

		return message;
	}

	google::protobuf::Message* MessageSerializer::Deserialize(const void* buf, size_t bufSize,Pmd::ForwardNullUserPmd_CS *&nmdout)
	{
		if(!nmdout)
		{
			 nmdout = new Pmd::ForwardNullUserPmd_CS;
		}
		google::protobuf::io::ArrayInputStream stream(buf, bufSize);
		google::protobuf::io::CodedInputStream coded(&stream);
		google::protobuf::Message* ret= Deserialize(&coded,nmdout);
		//leftSize = coded.BytesUntilLimit();
		return ret;
	}
	google::protobuf::Message* MessageSerializer::Deserialize(const void* buf, size_t bufSize,Pmd::ForwardNullUserPmd_CS &nmdout)
	{
		google::protobuf::io::ArrayInputStream stream(buf, bufSize);
		google::protobuf::io::CodedInputStream coded(&stream);
		google::protobuf::Message* ret= Deserialize(&coded,&nmdout);
		//leftSize = coded.BytesUntilLimit();
		return ret;
	}
	int MessageSerializer::DeserializeMessageSize(const void* buf, size_t bufSize,size_t &sizeLen)
	{
		google::protobuf::io::ArrayInputStream stream(buf, bufSize);
		google::protobuf::io::CodedInputStream input(&stream);
		google::protobuf::uint32 ret = 0;
		if(input.ReadVarint32(&ret))
		{
			sizeLen = input.CurrentPosition();
		}
		return int(ret);
	}

	bool MessageSerializer::Register(unsigned char byCmd,unsigned char byParam, const Descriptor* typeDescriptor, bool bLua)
	{
		if(typeDescriptor == NULL)
		{
			Bwsdk::logger->error("MessageSerializer::Register err");
			return false;
		}
		const Message* prototype = MessageFactory::generated_factory()->GetPrototype(typeDescriptor);
		int nType = bLua ? 1 : 0;
		if(m_unserializeTable[nType][(byCmd<<8) + byParam] != NULL && m_unserializeTable[nType][(byCmd<<8) + byParam] != prototype)
		{
			Bwsdk::logger->error("MessageSerializer::Register insert err[%u,%u],%p,%p",byCmd,byParam,m_unserializeTable[nType][(byCmd<<8) + byParam],prototype);
			return false;
		}
		m_unserializeTable[nType][(byCmd<<8) + byParam] = prototype;
		m_serializeTable.insert(std::make_pair(typeDescriptor, (byCmd<<8) + byParam));
		return true;
	}

	bool MessageSerializer::Register(const EnumDescriptor* byCmdEnum,const std::string ns, bool bLua)
	{
		if(byCmdEnum == NULL)// || byParamEnum == NULL)
		{
			Bwsdk::logger->error("MessageSerializer::Register insert err");
			return false;
		}
		for(int i = 0; i < byCmdEnum->value_count(); i++)
		{
			const EnumValueDescriptor* item = byCmdEnum->value(i);
			const int c = item->number();
			std::size_t found = item->name().find_last_of("_");
			std::string cmdname = item->name().substr(found+1);
			const std::string paramtype = ns + "." + cmdname + ".Param";
			//Bwsdk::logger->debug("MessageSerializer::Register byCmdEnum:%d,%s,%s",c,paramtype.c_str(),item->name().c_str());
			const EnumDescriptor* byParamEnum = DescriptorPool::generated_pool()->FindEnumTypeByName(paramtype);
			if(byParamEnum == NULL)
			{
				Bwsdk::logger->error("MessageSerializer::Register err:%d,%s,%s",c,paramtype.c_str(),item->name().c_str());
				return false;
			}
			for(int i = 0; i < byParamEnum->value_count(); i++)
			{
				const EnumValueDescriptor* item = byParamEnum->value(i);
				if(c > 0 && c < 200 && item->name().find(cmdname.c_str()) == std::string::npos)
				{
					Bwsdk::logger->error("MessageSerializer::Register name err:%d,%s,%s,需要名字严格匹配规则",c,cmdname.c_str(),item->name().c_str());
					return false;
				}
				const int t = item->number();
				//Bwsdk::logger->debug("MessageSerializer::Register byParamEnum:[%d,%d],%s,%s",c,t,byParamEnum->full_name().c_str(),item->name().c_str());
				const Descriptor* message = DescriptorPool::generated_pool()->FindMessageTypeByName(ns + "." + item->name());
				if(message == NULL)
				{
					Bwsdk::logger->error("MessageSerializer::Register find err:[%d,%d],%s,%s",c,t,byParamEnum->full_name().c_str(),(ns + "." + item->name()).c_str());
					return false;
				}

				if(Register(c,t, message, bLua) == false)
				{
					Bwsdk::logger->error("MessageSerializer::Register insert err:[%d,%d],%s",c,t,byParamEnum->full_name().c_str());
					return false;
				}
				
				if (Bwsdk::IsHandleInCPP(message))
				{
					m_HandleInCPP[(c<<8) + t] = true;
				}
			}
		}
		return true;
	}
}
