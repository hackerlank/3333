// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: lobbypmd.proto

#ifndef PROTOBUF_lobbypmd_2eproto__INCLUDED
#define PROTOBUF_lobbypmd_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "pmd.pb.h"
// @@protoc_insertion_point(includes)

namespace Pmd {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_lobbypmd_2eproto();
void protobuf_AssignDesc_lobbypmd_2eproto();
void protobuf_ShutdownFile_lobbypmd_2eproto();

class Lobby;
class DELETE_ME;

enum Lobby_Param {
  Lobby_Param_DELETE_ME = 1
};
bool Lobby_Param_IsValid(int value);
const Lobby_Param Lobby_Param_Param_MIN = Lobby_Param_DELETE_ME;
const Lobby_Param Lobby_Param_Param_MAX = Lobby_Param_DELETE_ME;
const int Lobby_Param_Param_ARRAYSIZE = Lobby_Param_Param_MAX + 1;

const ::google::protobuf::EnumDescriptor* Lobby_Param_descriptor();
inline const ::std::string& Lobby_Param_Name(Lobby_Param value) {
  return ::google::protobuf::internal::NameOfEnum(
    Lobby_Param_descriptor(), value);
}
inline bool Lobby_Param_Parse(
    const ::std::string& name, Lobby_Param* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Lobby_Param>(
    Lobby_Param_descriptor(), name, value);
}
// ===================================================================

class Lobby : public ::google::protobuf::Message {
 public:
  Lobby();
  virtual ~Lobby();

  Lobby(const Lobby& from);

  inline Lobby& operator=(const Lobby& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Lobby& default_instance();

  void Swap(Lobby* other);

  // implements Message ----------------------------------------------

  Lobby* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Lobby& from);
  void MergeFrom(const Lobby& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef Lobby_Param Param;
  static const Param DELETE_ME = Lobby_Param_DELETE_ME;
  static inline bool Param_IsValid(int value) {
    return Lobby_Param_IsValid(value);
  }
  static const Param Param_MIN =
    Lobby_Param_Param_MIN;
  static const Param Param_MAX =
    Lobby_Param_Param_MAX;
  static const int Param_ARRAYSIZE =
    Lobby_Param_Param_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Param_descriptor() {
    return Lobby_Param_descriptor();
  }
  static inline const ::std::string& Param_Name(Param value) {
    return Lobby_Param_Name(value);
  }
  static inline bool Param_Parse(const ::std::string& name,
      Param* value) {
    return Lobby_Param_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:Pmd.Lobby)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_lobbypmd_2eproto();
  friend void protobuf_AssignDesc_lobbypmd_2eproto();
  friend void protobuf_ShutdownFile_lobbypmd_2eproto();

  void InitAsDefaultInstance();
  static Lobby* default_instance_;
};
// -------------------------------------------------------------------

class DELETE_ME : public ::google::protobuf::Message {
 public:
  DELETE_ME();
  virtual ~DELETE_ME();

  DELETE_ME(const DELETE_ME& from);

  inline DELETE_ME& operator=(const DELETE_ME& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const DELETE_ME& default_instance();

  void Swap(DELETE_ME* other);

  // implements Message ----------------------------------------------

  DELETE_ME* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const DELETE_ME& from);
  void MergeFrom(const DELETE_ME& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string mid = 1;
  inline bool has_mid() const;
  inline void clear_mid();
  static const int kMidFieldNumber = 1;
  inline const ::std::string& mid() const;
  inline void set_mid(const ::std::string& value);
  inline void set_mid(const char* value);
  inline void set_mid(const char* value, size_t size);
  inline ::std::string* mutable_mid();
  inline ::std::string* release_mid();
  inline void set_allocated_mid(::std::string* mid);

  // @@protoc_insertion_point(class_scope:Pmd.DELETE_ME)
 private:
  inline void set_has_mid();
  inline void clear_has_mid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* mid_;
  friend void  protobuf_AddDesc_lobbypmd_2eproto();
  friend void protobuf_AssignDesc_lobbypmd_2eproto();
  friend void protobuf_ShutdownFile_lobbypmd_2eproto();

  void InitAsDefaultInstance();
  static DELETE_ME* default_instance_;
};
// ===================================================================


// ===================================================================

// Lobby

// -------------------------------------------------------------------

// DELETE_ME

// optional string mid = 1;
inline bool DELETE_ME::has_mid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void DELETE_ME::set_has_mid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void DELETE_ME::clear_has_mid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void DELETE_ME::clear_mid() {
  if (mid_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    mid_->clear();
  }
  clear_has_mid();
}
inline const ::std::string& DELETE_ME::mid() const {
  // @@protoc_insertion_point(field_get:Pmd.DELETE_ME.mid)
  return *mid_;
}
inline void DELETE_ME::set_mid(const ::std::string& value) {
  set_has_mid();
  if (mid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    mid_ = new ::std::string;
  }
  mid_->assign(value);
  // @@protoc_insertion_point(field_set:Pmd.DELETE_ME.mid)
}
inline void DELETE_ME::set_mid(const char* value) {
  set_has_mid();
  if (mid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    mid_ = new ::std::string;
  }
  mid_->assign(value);
  // @@protoc_insertion_point(field_set_char:Pmd.DELETE_ME.mid)
}
inline void DELETE_ME::set_mid(const char* value, size_t size) {
  set_has_mid();
  if (mid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    mid_ = new ::std::string;
  }
  mid_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:Pmd.DELETE_ME.mid)
}
inline ::std::string* DELETE_ME::mutable_mid() {
  set_has_mid();
  if (mid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    mid_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:Pmd.DELETE_ME.mid)
  return mid_;
}
inline ::std::string* DELETE_ME::release_mid() {
  clear_has_mid();
  if (mid_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = mid_;
    mid_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void DELETE_ME::set_allocated_mid(::std::string* mid) {
  if (mid_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete mid_;
  }
  if (mid) {
    set_has_mid();
    mid_ = mid;
  } else {
    clear_has_mid();
    mid_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:Pmd.DELETE_ME.mid)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Pmd

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::Pmd::Lobby_Param> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Pmd::Lobby_Param>() {
  return ::Pmd::Lobby_Param_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_lobbypmd_2eproto__INCLUDED
