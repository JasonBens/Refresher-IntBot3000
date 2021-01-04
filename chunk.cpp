#include "chunk.h"

namespace chunky {

ChunkMaster::ChunkMaster() {
  chunks_ = GenerateChunks(0);
}

ChunkMaster::ChunkMaster(uint64_t num) {
  chunks_ = GenerateChunks(num);
}

std::vector<chunky::Chunk> ChunkMaster::GenerateChunks(uint64_t num) {
  int generation = 0;
  std::vector<chunky::Chunk> chunks;
  chunks.push_back(GenerateChunk(num, generation, chunks));
  return chunks; 
}

 chunky::Chunk ChunkMaster::GenerateChunk(uint64_t num, int generation, std::vector<chunky::Chunk>& chunks) {
  uint64_t current_num = num % 1000;
  auto current_chunk = chunky::Chunk(current_num, generation);
  
  uint64_t next_num = num/1000;
  if (next_num) {
    chunks.push_back(GenerateChunk(next_num, generation + 1, chunks));
  }
  return current_chunk;
}

uint64_t ChunkMaster::ToInt() const {
  uint64_t num = 0;
  for (auto chunk : chunks_) {
    num += chunk.ToInt();
  }
  return num;
}

std::string ChunkMaster::ToFormattedInt() const {
  std::string tmp_str = "";
  for (int i = 0; i < chunks_.size(); i++) {
    tmp_str += chunks_[i].ToFormattedInt(i == 0);
    if (!IsLastChunk(i)) {
      tmp_str += ",";  
    }
  }
  return tmp_str;
}

std::string ChunkMaster::ToString() const {
  std::string tmp_str = "";
  std::string chunk_str = "";
  int i =0;
  for (int i = 0; i < chunks_.size(); i++) {
    chunk_str = chunks_[i].ToString(i == 0);
    if (chunk_str.empty()) {
      continue;
    }
    if (!tmp_str.empty() && IsLastChunk(i)) {
      if (chunks_[i].ToInt() >= 100) {
        chunk_str = " " + chunk_str;
      } else {
        chunk_str = " and " + chunk_str;
      }
    } else if (!tmp_str.empty() && !IsLastChunk(i)) {
      chunk_str = " " + chunk_str;
    }
    tmp_str += chunk_str;
  }
  return tmp_str;
}

bool ChunkMaster::IsLastChunk(int i) const {
  return i == (chunks_.size() - 1);
}

// END OF CHUNKMASTER

Chunk::Chunk(int num, int gen) : num_(num), generation_(gen) {}

uint64_t Chunk::ToInt() const {
  return num_ * std::pow(1000.0, generation_); // TODO: Check if this is subject to floating point errors
}

std::string Chunk::ToFormattedInt(bool is_first_chunk) const {
  std::ostringstream oss;
  if (is_first_chunk) {
    oss << num_;
  } else {
    oss << std::setw(3) << std::setfill('0') << num_;
  }
  return oss.str();
}

std::string Chunk::ToString(bool is_first_chunk) const {
  if (num_ == 0) {
    if (is_first_chunk) {
      return "zero";
    } else {
      return "";
    }
  }
  
  int tmp_num = num_;
  std::string digit_string = "";
  if (tmp_num >= 100) {
    digit_string += HundredsToString(tmp_num);
    tmp_num %= 100;
  }

  if (tmp_num >= 20) {
    digit_string += TensToString(tmp_num);
    tmp_num %= 10;
  }

  if (tmp_num >= 10) {
    digit_string += TeensToString(tmp_num);
    tmp_num = 0;
  }

  if (tmp_num) {
    digit_string += OnesToString(tmp_num);
    tmp_num = 0;
  }

  return digit_string + gens_str_[generation_];
}

std::string Chunk::HundredsToString(int num) const {
  std::string tmp_str = ""; 
  tmp_str = ones_str_[GetHundreds(num)] + " hundred";
  if (num % 100 > 0) {
    tmp_str += " and ";
  }
  return tmp_str;
}

std::string Chunk::TensToString(int num) const {
  std::string tmp_str = "";
  tmp_str = tens_str_[GetTens(num)];
  if (num % 10 > 0) {
    tmp_str += "-";
  }
  return tmp_str; 
}

std::string Chunk::TeensToString(int num) const {
  return teens_str_[GetTeens(num)-10];
}

std::string Chunk::OnesToString(int num) const {
  return ones_str_[GetOnes(num)];
}

int Chunk::GetHundreds(int num) const {
  return num / 100;
}

int Chunk::GetTens(int num) const {
  return (num % 100) / 10;
}

int Chunk::GetTeens(int num) const {
  return num % 100;
}

int Chunk::GetOnes(int num) const {
  return num % 10;
}

}  // namespace chunky
