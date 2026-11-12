class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(),
            mx = max_element(nums.begin(), nums.end()) - nums.begin(),
            mn = min_element(nums.begin(), nums.end()) - nums.begin(),
            l = min(mn, mx), r = max(mn, mx);

        return min({r + 1, n - l, l + 1 + n - r});
    }
};