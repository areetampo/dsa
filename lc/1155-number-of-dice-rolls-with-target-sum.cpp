class Solution {
public:
    int MOD = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            vector<int> dp1(target + 1, 0);
            for (int j = target; j > 0; --j) {
                for (int z = 1; z <= k; ++z) {
                    if (j - z < 0) break;
                    dp1[j] = (dp1[j] + dp[j - z]) % MOD;
                }
            }
            swap(dp, dp1);
        }
        return dp[target];
        // dp[0][0] = 1;
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= target; ++j) {
        //         for (int z = 1; z <= k; ++z) {
        //             if (j - z < 0) break;
        //             dp[i][j] = (dp[i][j] + dp[i - 1][j - z]) % MOD;
        //         }
        //     }
        // }
    }    
};