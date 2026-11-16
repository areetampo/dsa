class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> v(nums.size() + 2, 1);
        int n = v.size();
        for (int i = 1; i < n-1; ++i) v[i] = nums[i-1];
        vector<vector<int>> dp(n, vector<int>(n, -101));
        // BCs (i = j) => 0 No matrix multiplication possible
        // i = 0 row empty as not started from there
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 0;
            dp[0][i] = 0;
        }
        // i > j section not accessed as matrix multiplication i x j where i < j
        // rest i < j left with +infinity as need to minimize cost
        // diagonal filling tabulation
        for (int x = 2; x <= n - 1; ++x) {
            for (int i = 1; i <= n - x; ++i) {
                int j = i - 1 + x;
                for (int k = i; k < j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + v[i - 1] * v[k] * v[j]);
                }
            }
        }
        return dp[1][n - 1];
    }
};