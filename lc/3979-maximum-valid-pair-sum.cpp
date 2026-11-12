class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        // 1 <= nums[i] <= 1e9
        int res = 0;
        for (int i = 0, mx = 0; i < nums.size() - k; i++) {
            mx = max(mx, nums[i]);
            res = max(res, mx + nums[i + k]);
        }
        return res;
    }
};