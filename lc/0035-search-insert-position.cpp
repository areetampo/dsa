class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //contains unique vals
        int l = 0, h = nums.size() - 1, m = -1;
        while (l <= h) {
            m = l + (h-l)/2;
            if (nums[m] == target) return m;
            if (target < nums[m]) h = m - 1;
            else l = m + 1;
        }
        return l;
    }
};