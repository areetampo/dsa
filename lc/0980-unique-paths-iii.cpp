class Solution {
public:
  int n, m, steps; vector<vector<int>> vis;
  int dfs(vector<vector<int>>& g, int i, int j) {
    if (g[i][j] == 2) return steps ? 0 : 1;
    vis[i][j] = 1;
    --steps;
    int res = 0;
    if (i + 1 < n && g[i + 1][j] != -1 && !vis[i + 1][j]) res += dfs(g, i + 1, j); 
    if (i - 1 >= 0 && g[i - 1][j] != -1 && !vis[i - 1][j]) res += dfs(g, i - 1, j); 
    if (j + 1 < m && g[i][j + 1] != -1 && !vis[i][j + 1]) res += dfs(g, i, j + 1); 
    if (j - 1 >= 0 && g[i][j - 1] != -1 && !vis[i][j - 1]) res += dfs(g, i, j - 1); 
    vis[i][j] = 0;
    ++steps;
    return res;
  }
  int uniquePathsIII(vector<vector<int>>& g) {
    n = g.size(), m = g[0].size();
    vis = vector<vector<int>>(n, vector<int>(m, 0));
    int si, sj;
    steps = 0;//total possible steps
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (g[i][j] == 1) {
          si = i; sj = j;
        } else if (g[i][j] != -1) ++steps;
      }
    }
    return dfs(g, si, sj);
  }
};