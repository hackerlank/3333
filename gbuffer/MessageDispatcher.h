///////////////////////////////////////////////////////////////////////////////
/// @brief : protobuf网络消息派发器
/// @author: 杨明哲 mail.ymz@163.com
/// @time  :
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <map>
#include "google/protobuf/message.h"
#include "bwsdk/Bwsdk.h"

namespace gbuffer {

	template<typename TMessageHandler>
	class MessageDispatcher
	{
	public:
		typedef TMessageHandler MessageHandler;
	private:
		typedef std::map<const google::protobuf::Descriptor*, MessageHandler> dispatch_table;
		dispatch_table m_table;
	public:
		void ListAll()
		{
			for(typename dispatch_table::iterator iter = m_table.begin() ; iter != m_table.end() ; iter ++)
			{
				Bwsdk::logger->error("MessageDispatcher GetHandler err:%s,%p",iter->first->full_name().c_str() , iter->second);
			}
		}
		bool Register(const google::protobuf::Descriptor* message, MessageHandler handler)
		{
			const std::pair<typename dispatch_table::const_iterator, bool> pair =
				m_table.insert(std::make_pair(message, handler));
			return pair.second;
		}

		bool GetHandler(const google::protobuf::Descriptor* descriptor, MessageHandler* handlerOUT) const
		{
			if(descriptor != NULL && handlerOUT != NULL)
			{
				typename dispatch_table::const_iterator it = m_table.find(descriptor);
				if(it != m_table.end())
				{
					*handlerOUT = it->second;
					return true;
				}
			}else{
				Bwsdk::logger->error("MessageDispatcher GetHandler err:%p,%p",descriptor , handlerOUT);
			}
			return false;
		}

		bool GetHandler(const google::protobuf::Message* msg, MessageHandler* handlerOUT) const
		{
			if(msg != NULL)
			{
				return GetHandler(msg->GetDescriptor(), handlerOUT);
			}else{
				Bwsdk::logger->error("MessageDispatcher GetHandler err:%p,%p",msg , handlerOUT);
			}
			return false;
		}
	};

	template<typename TMessage>
	struct MessageDispatcherRegister
	{
		template<typename TMessageDispatcher, typename TMessageHandler>
		MessageDispatcherRegister(TMessageDispatcher& dispatcher, TMessageHandler handler)
		{
			const bool ok = dispatcher.Register(TMessage::descriptor(),
				reinterpret_cast<typename TMessageDispatcher::MessageHandler>(handler));
			assert(ok && "Duplicate MessageDispatcher register.");
			Bwsdk::SetHandleInCPP(TMessage::descriptor());
		}
	};
}

