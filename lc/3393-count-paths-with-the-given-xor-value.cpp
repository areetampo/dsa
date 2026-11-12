class Solution {
public:
    int res = 0, mod = 1000000007;
    int f(vector<vector<int>>& g, int k, int i, int j, vector<vector<vector<int>>>& dp) {
        int n = g.size(), m = g[0].size();
        if (i < n && j < m && dp[i][j][k ^ g[i][j]] != -1) return dp[i][j][k ^ g[i][j]];
        if (i == n - 1 && j == m - 1 && ((k ^ g[i][j]) == 0)) {
            return dp[i][j][k ^ g[i][j]] = 1;
        }
        return dp[i][j][k ^ g[i][j]] = 
            ((i + 1 < n ? f(g, k ^ g[i][j], i + 1, j, dp) : 0) +
            (j + 1 < m ? f(g, k ^ g[i][j], i, j + 1, dp) : 0)) % mod;
    }
    int countPathsWithXorValue(vector<vector<int>>& g, int k) {
        int n = g.size(), m = g[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(17, -1)));
        f(g, k, 0, 0, dp);
        return dp[0][0][k ^ g[0][0]];
    }
};