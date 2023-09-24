#include <cstdint>
#include <iostream>

int main() {
  uint32_t random, N;
  int32_t min, max;

  std::cin >> random >> N >> min >> max;

  for(int i = 0; i < N; i++)
  {
    random ^= random << 13;
    random ^= random >> 17;
    random ^= random << 5;

    // Clamp in range
    std::cout << min + random % (max - min + 1) << std::endl;
  }

}
