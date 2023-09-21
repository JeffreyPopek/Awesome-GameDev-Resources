#include <cstdint>
#include <iostream>

using namespace std;
int main() {
  // Seed, number of random numbers, Range 1, Range 2
  //  uint32_t S = 2;
  //  uint32_t N = 10;
  //  int32_t min = 20;
  //  int32_t max = 89;
  uint32_t S, N;
  int32_t min, max;

  cin >> S >> N >> min >> max;

  int value, random;

  random = S;

  for(int i = 0; i < N; i++)
  {
    random ^= random << 13;
    random ^= random >> 17;
    random ^= random << 5;

    // Clamp in range
    value = min + abs(random) % (max - min + 1);

    //cout << "Random: " << random << " Value: " << value << endl;

    cout << value << endl;
  }

}
