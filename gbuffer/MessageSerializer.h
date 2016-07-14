///////////////////////////////////////////////////////////////////////////////
/// @brief : protobuf消息的序列化/反序列化器
/// @author: 杨明哲 mail.ymz@163.com
/// @time  : 2012年6月25日13:36:52
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <map>
#include <stdlib.h>
#include "google/protobuf/message.h"
#include "google/protobuf/io/coded_stream.h"

namespace Pmd{
	class ForwardNullUserPmd_CS;
}
namespace google{ namespace protobuf{
	class Descriptor;
	class Message;
	class EnumDescriptor;
}}
	
namespace gbuffer {
	
	int VarintSize32(unsigned int value);
	// 封包结构: {<category, type><Command>}
	/// @ref https://developers.google.com/protocol-buffers/docs/techniques#streaming
	class MessageSerializer
	{
	public:
		MessageSerializer();
		typedef std::map<const google::protobuf::Descriptor*, unsigned int> serialize_table;
		typedef std::map<unsigned int, const google::protobuf::Message*> unserialize_table;
		
	private:
		serialize_table m_serializeTable;
		const google::protobuf::Message* m_unserializeTable[2][65536];
		bool m_HandleInCPP[65536];
	public:
		bool Register(unsigned char byCmd,unsigned char byParam, const google::protobuf::Descriptor* typeDescriptor, bool bLua = false);
		bool Register(const google::protobuf::EnumDescriptor* byCmdEnum,const std::string ns, bool bLua = false);

	public:
		/// @return 序列化后的字节数，失败时<0
		int Serialize(const google::protobuf::Message* message, google::protobuf::io::CodedOutputStream* output,bool needlen=false) const;
		int Serialize(const google::protobuf::Message* message, void* bufOUT, size_t bufSize,bool needlen=false) const;
		int GetMessageCmd(const google::protobuf::Message* message) const;
		int GetMessageParam(const google::protobuf::Message* message) const;
		int SerializeMessageSize(int msglen, void* bufOUT, size_t bufSize) const;
		/// @return 失败返回NULL。须由用户负责回收内存
		google::protobuf::Message* Deserialize(google::protobuf::io::CodedInputStream* input,Pmd::ForwardNullUserPmd_CS *nmdout) const;
		google::protobuf::Message* Deserialize(const void* buf, size_t bufSize,Pmd::ForwardNullUserPmd_CS *&nmdout);
		google::protobuf::Message* Deserialize(const void* buf, size_t bufSize,Pmd::ForwardNullUserPmd_CS &nmdout);
		int DeserializeMessageSize(const void* buf, size_t bufSize,size_t &sizeLen);
	};
	bool RegisterMessage(MessageSerializer* serializer);
}

