class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (dp[i] != INT_MAX) {
                for (int j = 1; j <= nums[i]; ++j) {
                    if (i + j == nums.size() - 1) return dp[i] + 1;
                    dp[i+j] = min(dp[i+j], 1 + dp[i]);
                }
            }
        }
        return dp[dp.size() - 1];
    }
};