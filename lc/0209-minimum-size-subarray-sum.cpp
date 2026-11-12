class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, i = 0, j = 0, runningSum = 0;
        while (j < nums.size()) {
            runningSum += nums[j++];
            while (runningSum >= target) {
                ans = min(ans, j-i);
                runningSum -= nums[i++];
            }
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};