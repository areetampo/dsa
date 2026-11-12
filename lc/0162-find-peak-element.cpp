class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) return (nums[0] > nums[1]) ? 0 : 1;
        int l = 0, h = nums.size() - 1, m = -1;
        while (l <= h) {
            m = l + (h-l)/2;
            if ((m == 0 || m == nums.size() - 1) || (nums[m-1] < nums[m] && nums[m] > nums[m+1])) break;
            if (nums[m] > nums[m+1]) h = m;
            if (nums[m] < nums[m+1]) l = m + 1;
        }
        return m;
    }
};