class Solution {
public:
    vector<vector<vector<int>>> dp;
    int dfs(vector<vector<int>>& g, int i = 0, int j = 0, int p = 2) {
        int n = g.size(), m = g[0].size();
        if (dp[i][j][p] != INT_MIN) return dp[i][j][p];
        if (i == n - 1 && j == m - 1) {
            if (p > 0 && g[i][j] < 0) return dp[i][j][p] = 0;
            return dp[i][j][p] = g[i][j];
        }
        int a = INT_MIN, b = INT_MIN, c = INT_MIN, d = INT_MIN;
        if (i + 1 < n)
            a = g[i][j] + dfs(g, i + 1, j, p);
        if (j + 1 < m)
            b = g[i][j] + dfs(g, i, j + 1, p);
        if (p > 0 && g[i][j] < 0) {
            if (i + 1 < n)
            c = dfs(g, i + 1, j, p - 1);
            if (j + 1 < m) 
            d = dfs(g, i, j + 1, p - 1);
        }
        return dp[i][j][p] = max({a,b,c,d});
    }
    int maximumAmount(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));
        return dfs(g);
    }
};