#include <iostream>
#include "superint.h"

int main() {
  superint::SuperInt si;
  uint64_t n;

  n = 0;                   std::cout << si.ToFormattedInt(n) <<" is " << si.ToString(n) << std::endl;
  n = 3;                   std::cout << si.ToFormattedInt(n) <<" is " << si.ToString(n) << std::endl;
  n = 47;                  std::cout << si.ToFormattedInt(n) <<" is " << si.ToString(n) << std::endl;
  n = 73;                  std::cout << si.ToFormattedInt(n) <<" is " << si.ToString(n) << std::endl;
  n = 1492;                std::cout << si.ToFormattedInt(n) <<" is " << si.ToString(n) << std::endl;
  n = 10012;               std::cout << si.ToFormattedInt(n) <<" is " << si.ToString(n) << std::endl;
  n = 100073;              std::cout << si.ToFormattedInt(n) <<" is " << si.ToString(n) << std::endl;
  n = 1000000;             std::cout << si.ToFormattedInt(n) <<" is " << si.ToString(n) << std::endl;
  n = 1000000001;          std::cout << si.ToFormattedInt(n) <<" is " << si.ToString(n) << std::endl;
  n = 123000000000;        std::cout << si.ToFormattedInt(n) <<" is " << si.ToString(n) << std::endl;
  n = 474142398123;        std::cout << si.ToFormattedInt(n) <<" is " << si.ToString(n) << std::endl;
  n = 1474142398007;       std::cout << si.ToFormattedInt(n) <<" is " << si.ToString(n) << std::endl;
  n = 999000000000000;     std::cout << si.ToFormattedInt(n) <<" is " << si.ToString(n) << std::endl;
  n = 999999999999999999;  std::cout << si.ToFormattedInt(n) <<" is " << si.ToString(n) << std::endl;
  n = 1000000000000000000; std::cout << si.ToFormattedInt(n) <<" is " << si.ToString(n) << std::endl;

  return 0;
}