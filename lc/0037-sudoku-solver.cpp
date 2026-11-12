class Solution {
public:
  bool isValid(int i, int j, vector<vector<char>>& g) {
    for (int x = 0; x < 9; ++x) 
      if (x != j && g[i][x] == g[i][j] || x != i && g[x][j] == g[i][j]) return 0;
    int I = i / 3 * 3, J = j / 3 * 3;
    for (int x = 0; x < 3; ++x) {
      for (int y = 0; y < 3; ++y) {
        if (I + x != i && J + y != j && g[I + x][J + y] == g[i][j]) return 0;
      }
    }
    return 1;
  }
  bool dfs(int i, int j, vector<vector<char>>& g) {
    if (j == 9) { ++i; j = 0; }
    if (i == 9) return 1;
    if (g[i][j] == '.') {
      for (int x = 1; x <= 9; ++x) {
        g[i][j] = x + '0';
        if (isValid(i, j, g) && dfs(i, j + 1, g)) return 1;
      }
      g[i][j] = '.';
      return 0;
    }
    return dfs(i, j + 1, g);
  }
  void solveSudoku(vector<vector<char>>& g) {
    dfs(0, 0, g);
  }
};