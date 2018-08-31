// This file must contain all the data structures which can be used as a key or a value  for LMDB dictionary.
#ifndef _LMDB_VALUES_H__
#define _LMDB_VALUES_H__

#include <memory>
#include <cstring>

namespace LMDB {

// An abstract class to derive from for all LMDB key/values.
class LMDBType {
public:
  // Returns byte length of the current element.
  virtual uint32_t byte_length() const = 0;

  // Writes current value into a pre-allocated byte array.
  virtual void to_byte_array(char* buffer) const = 0;

  // Reads the value from the byte array.
  virtual void from_byte_array(uint32_t size, const char* buffer) = 0;
};

// Serves as a sample of key class to be stored in LMDB.
class SampleKey : public LMDBType {
public:
  SampleKey() = default;
  SampleKey(uint32_t key);

  // Returns byte length of the current element.
  uint32_t byte_length() const override;

  // Writes current value into a pre-allocated byte array.
  void to_byte_array(char* buffer) const override;

  // Reads the value from the byte array.
  void from_byte_array(uint32_t size, const char* buffer) override;

  bool operator==(const SampleKey& other) const;

  uint32_t key_;
};

// Serves as a sample of value class to be stored in LMDB.
class SampleValue : public LMDBType {
public:
    SampleValue() = default;
    SampleValue(uint32_t value1, uint32_t value2);

    // Returns byte length of the current element.
    uint32_t byte_length() const override;

    // Writes current value into a pre-allocated byte array.
    void to_byte_array(char* buffer) const override;

    // Reads the value from the byte array.
    void from_byte_array(uint32_t size, const char* buffer) override;

    bool operator==(const SampleValue& other) const;

    uint32_t value1_;
    uint32_t value2_;
};

} // namespace LMDB

#endif // _LMDB_VALUES_H__
