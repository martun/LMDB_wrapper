#include "lmdb_values.h"
#include <string>

namespace LMDB {

OffsetRange::OffsetRange(uint32_t start_offset, uint32_t end_offset)
  : start_offset(start_offset)
  , end_offset(end_offset)
{
}

uint32_t OffsetRange::byte_length() const {
  return sizeof(start_offset) + sizeof(end_offset);
}

void OffsetRange::to_byte_array(char* buffer) const {
  std::memcpy(buffer, &start_offset, sizeof(start_offset));
  std::memcpy(buffer + sizeof(start_offset), &end_offset, sizeof(end_offset));
}

void OffsetRange::from_byte_array(uint32_t size, const char* buffer) {
  std::memcpy(&start_offset, buffer, sizeof(start_offset));
  std::memcpy(&end_offset, buffer + sizeof(start_offset), sizeof(end_offset));
}

} // namespace LMDB

