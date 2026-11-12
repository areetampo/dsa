class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(), nums.rend());
        long long res = 0;
        for (int i : nums) { // all +ve in nums
            res += (long long)i * max(1, mul--);
            if (--k == 0) break;
        }
        return res;
    }
};