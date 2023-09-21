#include <iostream>
using namespace std;

int main() {
  int C, L, T;
  cin >> C >> L >> T;

  const int gridColumn = C;
  const int gridLine = L;

  bool Grid[gridLine][gridColumn];
  bool NextGrid[gridLine][gridColumn];

  // Init Grid
  char temp;
  for (int i = 0; i < L; i++) {
    for (int j = 0; j < C; j++) {
      cin >> temp;
      Grid[i][j] = (temp == '#');
    }
  }

  // Turns
  while (T > 0) {
    for (int i = 0; i < L; i++) {
      for (int j = 0; j < C; j++) {
        int liveNeighbors = 0;

        for (int x = -1; x <= 1; x++) {
          for (int y = -1; y <= 1; y++) {
            if (x == 0 && y == 0) continue; // Skip the cell itself
            int newX = (i + x + L) % L; // Wrap around vertically
            int newY = (j + y + C) % C; // Wrap around horizontally

            if (Grid[newX][newY]) {
              liveNeighbors++;
            }
          }
        }

        if (Grid[i][j]) { // Current cell is alive
          if (liveNeighbors < 2 || liveNeighbors > 3) {
            NextGrid[i][j] = false; // Die
          } else {
            NextGrid[i][j] = true; // Continue to live
          }
        } else { // Current cell is dead
          if (liveNeighbors == 3) {
            NextGrid[i][j] = true; // Reproduce
          } else {
            NextGrid[i][j] = false; // Stay dead
          }
        }
      }
    }

    // Copy the next generation back to the original grid
    for (int i = 0; i < L; i++) {
      for (int j = 0; j < C; j++) {
        Grid[i][j] = NextGrid[i][j];
      }
    }

    T--;
  }

  // Display grid
  for (int i = 0; i < L; i++) {
    for (int j = 0; j < C; j++) {
      if (Grid[i][j]) {
        cout << "#";
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }

  return 0;
}