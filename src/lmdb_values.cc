#include "lmdb_values.h"
#include <string>

namespace LMDB {

  SampleKey::SampleKey(uint32_t key)
          : key_(key)
  {
  }

  uint32_t SampleKey::byte_length() const {
    return sizeof(key_);
  }

  void SampleKey::to_byte_array(char* buffer) const {
    std::memcpy(buffer, &key_, sizeof(key_));
  }

  void SampleKey::from_byte_array(uint32_t size, const char* buffer) {
    std::memcpy(&key_, buffer, sizeof(key_));
  }

  bool SampleKey::operator==(const SampleKey& other) const
  {
    return key_ == other.key_;
  }


  SampleValue::SampleValue(uint32_t value1, uint32_t value2)
          : value1_(value1)
          , value2_(value2)
  {
  }

  uint32_t SampleValue::byte_length() const {
    return sizeof(value1_) + sizeof(value2_);
  }

  void SampleValue::to_byte_array(char* buffer) const {
    std::memcpy(buffer, &value1_, sizeof(value1_));
    std::memcpy(buffer + sizeof(value1_), &value2_, sizeof(value2_));
  }

  void SampleValue::from_byte_array(uint32_t size, const char* buffer) {
    std::memcpy(&value1_, buffer, sizeof(value1_));
    std::memcpy(&value2_, buffer + sizeof(value1_), sizeof(value2_));
  }

  bool SampleValue::operator==(const SampleValue& other) const
  {
    return value1_ == other.value1_ && value2_ == other.value2_;
  }

} // namespace LMDB

