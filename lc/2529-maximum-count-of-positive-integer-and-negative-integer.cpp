class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int l = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int n = nums.size();
        return max(l, n - r);
    }
};