// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: config.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "config.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Pmd {

namespace {

const ::google::protobuf::Descriptor* Config_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Config_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* Config_Version_descriptor_ = NULL;
const ::google::protobuf::EnumDescriptor* Config_Debug_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_config_2eproto() {
  protobuf_AddDesc_config_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "config.proto");
  GOOGLE_CHECK(file != NULL);
  Config_descriptor_ = file->message_type(0);
  static const int Config_offsets_[1] = {
  };
  Config_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Config_descriptor_,
      Config::default_instance_,
      Config_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Config, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Config, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Config));
  Config_Version_descriptor_ = Config_descriptor_->enum_type(0);
  Config_Debug_descriptor_ = Config_descriptor_->enum_type(1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_config_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Config_descriptor_, &Config::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_config_2eproto() {
  delete Config::default_instance_;
  delete Config_reflection_;
}

void protobuf_AddDesc_config_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\014config.proto\022\003Pmd\"\210\002\n\006Config\"\322\001\n\007Versi"
    "on\022\024\n\rVersion_Login\020\200\365\315\t\022\023\n\014Version_Game"
    "\020\200\365\315\t\022\021\n\nVersion_Gm\020\200\365\315\t\022\026\n\017Version_Gate"
    "way\020\200\365\315\t\022\024\n\rVersion_NameS\020\200\365\315\t\022\026\n\017Versio"
    "n_Monitor\020\200\365\315\t\022\022\n\013Version_Sdk\020\200\365\315\t\022\024\n\rVe"
    "rsion_Build\020\200\365\315\t\022\025\n\016Version_Logger\020\362\300\316\t\032"
    "\002\020\001\")\n\005Debug\022\r\n\tDebug_All\020\001\022\r\n\tDebug_Whj"
    "\020\001\032\002\020\001", 286);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "config.proto", &protobuf_RegisterTypes);
  Config::default_instance_ = new Config();
  Config::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_config_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_config_2eproto {
  StaticDescriptorInitializer_config_2eproto() {
    protobuf_AddDesc_config_2eproto();
  }
} static_descriptor_initializer_config_2eproto_;

// ===================================================================

const ::google::protobuf::EnumDescriptor* Config_Version_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Config_Version_descriptor_;
}
bool Config_Version_IsValid(int value) {
  switch(value) {
    case 20150912:
    case 20160626:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const Config_Version Config::Version_Login;
const Config_Version Config::Version_Game;
const Config_Version Config::Version_Gm;
const Config_Version Config::Version_Gateway;
const Config_Version Config::Version_NameS;
const Config_Version Config::Version_Monitor;
const Config_Version Config::Version_Sdk;
const Config_Version Config::Version_Build;
const Config_Version Config::Version_Logger;
const Config_Version Config::Version_MIN;
const Config_Version Config::Version_MAX;
const int Config::Version_ARRAYSIZE;
#endif  // _MSC_VER
const ::google::protobuf::EnumDescriptor* Config_Debug_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Config_Debug_descriptor_;
}
bool Config_Debug_IsValid(int value) {
  switch(value) {
    case 1:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const Config_Debug Config::Debug_All;
const Config_Debug Config::Debug_Whj;
const Config_Debug Config::Debug_MIN;
const Config_Debug Config::Debug_MAX;
const int Config::Debug_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
#endif  // !_MSC_VER

Config::Config()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Pmd.Config)
}

void Config::InitAsDefaultInstance() {
}

Config::Config(const Config& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Pmd.Config)
}

void Config::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Config::~Config() {
  // @@protoc_insertion_point(destructor:Pmd.Config)
  SharedDtor();
}

void Config::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Config::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Config::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Config_descriptor_;
}

const Config& Config::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_config_2eproto();
  return *default_instance_;
}

Config* Config::default_instance_ = NULL;

Config* Config::New() const {
  return new Config;
}

void Config::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Config::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Pmd.Config)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0 ||
        ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, mutable_unknown_fields()));
  }
success:
  // @@protoc_insertion_point(parse_success:Pmd.Config)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Pmd.Config)
  return false;
#undef DO_
}

void Config::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Pmd.Config)
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Pmd.Config)
}

::google::protobuf::uint8* Config::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Pmd.Config)
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Pmd.Config)
  return target;
}

int Config::ByteSize() const {
  int total_size = 0;

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Config::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Config* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Config*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Config::MergeFrom(const Config& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Config::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Config::CopyFrom(const Config& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Config::IsInitialized() const {

  return true;
}

void Config::Swap(Config* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Config::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Config_descriptor_;
  metadata.reflection = Config_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Pmd

// @@protoc_insertion_point(global_scope)
