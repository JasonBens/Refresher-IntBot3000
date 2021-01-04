#ifndef CHUNK_
#define CHUNK_

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cmath>

namespace chunky {

class Chunk {
 public:
  Chunk(int, int);
  uint64_t ToInt() const;
  std::string ToFormattedInt(bool) const;
  std::string ToString(bool) const; 
 private:
  int num_ = 0;
  int generation_ = 0;
  std::string HundredsToString(int) const;
  std::string TensToString(int) const;
  std::string TeensToString(int) const;
  std::string OnesToString(int) const;
  int GetHundreds(int num) const;
  int GetTens(int num) const;
  int GetTeens(int num) const;
  int GetOnes(int num) const;
  const std::string ones_str_[10] = {""    , "one", "two"  , "three", "four",
                                     "five", "six", "seven", "eight", "nine"};
  const std::string teens_str_[10] = {"ten"    , "eleven" , "twelve"   , "thirteen", "fourteen",
                                      "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  const std::string tens_str_[10] {""     , ""     , "twenty" , "thirty", "forty" ,
                                   "fifty", "sixty", "seventy", "eighty", "ninety"};
  const std::string gens_str_[7] = {""         , " thousand"   , " million"    ," billion",
                                    " trillion", " quadrillion", " quintillion"};
};

class ChunkMaster {
 public:
  ChunkMaster();
  ChunkMaster(uint64_t);
  uint64_t ToInt() const;
  std::string ToFormattedInt() const;
  std::string ToString() const; 
 private:
  bool IsLastChunk(int) const;
  std::vector<chunky::Chunk> chunks_;
  std::vector<chunky::Chunk> GenerateChunks(uint64_t);
  chunky::Chunk GenerateChunk(uint64_t, int, std::vector<chunky::Chunk>&);
};

}  // namespace chunky

#endif  // CHUNK_