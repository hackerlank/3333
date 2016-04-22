///////////////////////////////////////////////////////////////////////////////
/// @brief : Google Protocol Buffers 实用辅助
/// @author: 杨明哲  mail.ymz@163.com
/// @time  : 2011年9月5日18:57:33
///////////////////////////////////////////////////////////////////////////////
#pragma once

namespace google{ namespace protobuf{
	template<typename Element>
	class RepeatedPtrField;
}}

namespace gbuffer {
	class Utility
	{
	public:
		/// @brief 删除repeated中给定下标的节点
		template<typename Element>
		static bool Remove(::google::protobuf::RepeatedPtrField<Element>* repeated, int index)
		{
			if(repeated != 0 && index >= 0 && index < repeated->size())
			{
				Element** p = repeated->mutable_data();
				Element* remove = p[index];
				std::copy(p + index + 1, p + repeated->size(), p + index);
				p[repeated->size() - 1] = remove;
				repeated->RemoveLast();
				return true;
			}
			return false;
		}

		/// @brief 删除repeated中给定的节点
		template<typename Element>
		static bool Remove(::google::protobuf::RepeatedPtrField<Element>* repeated, Element* element)
		{
			if(repeated != 0)
			{
				const ::google::protobuf::RepeatedPtrField<Element>::pointer_iterator p = 
					std::find(repeated->pointer_begin(), repeated->pointer_end(), element);
				if(p != repeated->pointer_end())
					return Remove(repeated, std::distance(repeated->pointer_begin(), p));
			}
			return false;
		}
	};
}

