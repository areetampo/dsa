class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        int res = 0;
        int i = 1;
        while (i < n-1) {
            if (nums[i-1] - nums[i] == nums[i] - nums[i+1]) {
                int j = i + 1;
                while (j < n-1 && nums[j-1] - nums[j] == nums[j] - nums[j+1]) { ++j; }
                int size = j - i + 2;
                res += (size - 1)*(size-2)/2;
                i = j + 1;
            }
            else ++i;
        }
        return res;
    }
};