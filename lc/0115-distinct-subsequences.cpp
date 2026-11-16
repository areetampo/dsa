class Solution {
public:
    int numDistinct(string s, string t) { 
        // find subsqn in s that equal t
        int n = s.length(), m = t.length();
        // ll since intermediate dp values can exceed i32 even though dp[n][m] < i32
        const long long LIMIT = 1e18; // but some can exceed ll_max
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, -1));

        dp[0][0] = 1;
        fill(dp[0].begin() + 1, dp[0].end(), 0);
        for (int i = 1; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1]) 
                    dp[i][j] = min(dp[i][j] + dp[i - 1][j - 1], LIMIT);
            }

        return dp[n][m];
    }
};