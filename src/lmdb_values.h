// This file must contain all the data structures which can be used as a key or a value  for LMDB dictionary.
#ifndef _LMDB_VALUES_H__
#define _LMDB_VALUES_H__

#include <memory>
#include <cstring>
#include "common/common.h"
#include "bitmap_index/index_utils.h"
#include "value_decomposer.h"

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

// Used to store offset ranges. Serves as a sample of class to be stored in LMDB.
class OffsetRange : public LMDBType {
public:
  OffsetRange() = default;
  OffsetRange(uint32_t start_offset, uint32_t end_offset);

  // Returns byte length of the current element.
  uint32_t byte_length() const override;

  // Writes current value into a pre-allocated byte array.
  void to_byte_array(char* buffer) const override;

  // Reads the value from the byte array.
  void from_byte_array(uint32_t size, const char* buffer) override;

  uint32_t start_offset;
  uint32_t end_offset;
};

} // namespace LMDB

#endif // _LMDB_VALUES_H__
