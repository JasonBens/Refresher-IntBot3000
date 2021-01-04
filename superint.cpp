#include "superint.h"

namespace superint {

SuperInt::SuperInt() {
  chunk_master_ = chunky::ChunkMaster(0);
}

SuperInt::SuperInt(uint64_t num) {
  chunk_master_ = chunky::ChunkMaster(num);
}

std::string SuperInt::ToString() {
  return chunk_master_.ToString();
}

std::string SuperInt::ToFormattedInt() {
  return chunk_master_.ToFormattedInt();
}

// Static Members

std::string SuperInt::ToString (uint64_t num) {
  auto chunk_master = chunky::ChunkMaster(num);
  return chunk_master.ToString();
}

std::string SuperInt::ToFormattedInt(uint64_t num) {
  auto chunk_master = chunky::ChunkMaster(num);
  return chunk_master.ToFormattedInt();
}

}  //  namespace superint
