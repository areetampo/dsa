class Solution {
public:
  int n, m;
  string s;
  vector<vector<char>> g;
  vector<vector<int>> vis;
  bool f(int i, int j, int idx) {
    if (s[idx] != g[i][j]) return 0;
    if (idx == s.length() - 1) return 1;
    vis[i][j] = 1;
    bool a = 0, b = 0, c = 0, d = 0;
    if (i + 1 < n && !vis[i + 1][j]) a = f(i + 1, j, idx + 1);
    if (i - 1 >= 0 && !vis[i - 1][j]) b = f(i - 1, j, idx + 1);
    if (j + 1 < m && !vis[i][j + 1]) c = f(i, j + 1, idx + 1);
    if (j - 1 >= 0 && !vis[i][j - 1]) d = f(i, j - 1, idx + 1);
    vis[i][j] = 0;
    return a || b || c || d;
  }
  bool exist(vector<vector<char>>& board, string word) {
    g = board;
    n = g.size(), m = g[0].size();
    s = word;
    vis = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (f(i, j, 0)) return 1;
      }
    }
    return 0;
  }
};