#ifndef SUPERINT_
#define SUPERINT_

#include <string>
#include <iostream>
#include "chunk.h"

namespace superint {

class SuperInt {
 public:
  SuperInt();
  SuperInt(uint64_t);
  std::string ToString();
  std::string ToFormattedInt();
  static std::string ToString(uint64_t);
  std::string ToFormattedInt(uint64_t);
 private:
  chunky::ChunkMaster chunk_master_;
  chunky::ChunkMaster GenerateChunks(uint64_t);
};

}  //  namespace superint

#endif  // SUPERINT_