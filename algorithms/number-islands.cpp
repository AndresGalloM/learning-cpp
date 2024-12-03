#include <iostream>

int numIslands(int island[3][5]);
void dfs(int island[3][5], bool visited[3][5], int y, int x);

int main() {
  int island[3][5] = {
    {1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0},
    {0, 0, 0, 0, 1}
  };

  int total = numIslands(island);
  std::cout << "Total of islands: " << total << std::endl; 

  return 0;
}

int numIslands(int island[3][5]) {
  bool visited[3][5] = {};
  int countIslands = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      if (!visited[i][j] && island[i][j] == 1) {
        dfs(island, visited, i, j);
        countIslands++;
      }
    }
  }

  return countIslands;
}

void dfs(int island[3][5], bool visited[3][5], int y, int x) {
  visited[y][x] = true;

  if (y - 1 >= 0 && island[y - 1][x] == 1 && !visited[y - 1][x]) dfs(island, visited, y - 1, x);
  if (y + 1 <= 3 && island[y + 1][x] == 1 && !visited[y + 1][x]) dfs(island, visited, y + 1, x);
  if (x - 1 >= 0 && island[y][x - 1] == 1 && !visited[y][x - 1]) dfs(island, visited, y, x - 1);
  if (x + 1 <= 5 && island[y][x + 1] == 1 && !visited[y][x + 1]) dfs(island, visited, y, x + 1);
}

