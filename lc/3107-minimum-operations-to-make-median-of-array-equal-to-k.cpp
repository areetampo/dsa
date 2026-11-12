class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long res = 0;
        int m = n / 2;
        if (nums[m] > k) {
            res += nums[m] - k;
            for (int i = m - 1; i >= 0; --i) {
                if (nums[i] <= k) break;
                res += nums[i] - k;
            }
        }
        else if (nums[m] < k) {
            res += k - nums[m];
            for (int i = m + 1; i < n; ++i) {
                if (nums[i] >= k) break;
                res += k - nums[i];
            }
        }
        return res;   
    }
};