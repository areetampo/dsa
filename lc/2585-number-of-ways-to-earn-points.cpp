class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {//1d dp
        int MOD = 1e9 + 7, n = types.size();
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int cnt = types[i-1][0], marks = types[i-1][1];
            for (int j = target; j > 0; --j) {//reverse so can read left vals for updating of right vals
                for (int k = 1; k <= cnt; ++k)//k from 1 since the dp[i-1][j] alr in the cell
                dp[j] = (dp[j] + (j - k * marks >= 0 ? dp[j-k*marks] : 0)) % MOD;
            }
        }
        return dp[target];
    }
    // int waysToReachTarget(int target, vector<vector<int>>& types) {//2d dp
    //     int MOD = 1e9 + 7, n = types.size();
    //     vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    //     for (int i = 0; i <= n; ++i) dp[i][0] = 1;
    //     for (int i = 1; i <= n; ++i) {
    //         int cnt = types[i-1][0], marks = types[i-1][1];
    //         for (int j = 1; j <= target; ++j) {
    //             for (int k = 0; k <= cnt; ++k) 
    //             dp[i][j] = (dp[i][j] + (j - k * marks >= 0 ? dp[i-1][j-k*marks] : 0)) % MOD;
    //         }
    //     }
    //     return dp[n][target];
    // }
};