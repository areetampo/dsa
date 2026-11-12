class Solution {
public:
    int mod = 1e9 + 7;
    int dfs(int r, int c, int moves, int n, int m, vector<vector<vector<int>>>& dp) {
        if (moves < 0) return 0;
        if (r == n || c == m || r < 0 || c < 0) return 1;
        if (dp[r][c][moves] != -1) return dp[r][c][moves];
        int val = 0;
        val = (val + dfs(r + 1, c, moves - 1, n, m, dp)) % mod;
        val = (val + dfs(r - 1, c, moves - 1, n, m, dp)) % mod;
        val = (val + dfs(r, c + 1, moves - 1, n, m, dp)) % mod;
        val = (val + dfs(r, c - 1, moves - 1, n, m, dp)) % mod;
        return dp[r][c][moves] = val;
    }
    int findPaths(int n, int m, int moves, int sr, int sc) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(moves + 1, -1)));
        return dfs(sr, sc, moves, n, m, dp);
    }
};