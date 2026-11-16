class Solution {
public:
    int maximumLength(vector<int>& v, int k) {
        int n = v.size(), res = 1;
        vector<vector<int>> dp(n, vector<int>(k + 1, 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int l = 0; l < i; l++) {
                    if (v[i] == v[l]) {
                        dp[i][j] = max(dp[i][j], dp[l][j] + 1);
                    } else if (j > 0) {
                        dp[i][j] = max(dp[i][j], dp[l][j - 1] + 1);
                    }
                    res = max(res, dp[i][j]);
                }
                
            }
        }
        return res;
    }
};