class Solution {
public:
  int n;
  vector<vector<int>> v;
  bool isValid(int i, int j) {
      for (int x = 0; x < n; ++x)
          if (x != j && v[i][x] || x != i && v[x][j]) return 0;
      //always placing at next row so no need to check below rows since no queens there
      for (int x = i - 1, y = j - 1; x >= 0 && y >= 0; --x, --y)
          if (v[x][y]) return 0;
      for (int x = i - 1, y = j + 1; x >= 0 && y < n; --x, ++y)
          if (v[x][y]) return 0;
      return 1;
  }
  int dfs(int i) {
      if (i == n) return 1;
      int res = 0;
      for (int j = 0; j < n; ++j) {
          v[i][j] = 1;
          if (isValid(i, j)) res += dfs(i + 1);
          v[i][j] = 0;
      }
      return res;
  }
  int totalNQueens(int N) {
      n = N;
      v = vector<vector<int>>(n, vector<int>(n, 0));
      return dfs(0);
  }
};