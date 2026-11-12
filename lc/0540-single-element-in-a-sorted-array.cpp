class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];//NOTE: nums size always odd
        int l = 0, h = nums.size() - 1;
        int m = -1;
        while (l <= h) {
            m = l + (h-l)/2;
            if (m == 0 || m == nums.size() - 1) break;
            if (nums[m] == nums[m+1]) {
                if (m % 2) h = m - 1;
                else l = m + 2;
            }
            else if (nums[m-1] == nums[m]) {
                if (m % 2) l = m + 1;
                else h = m - 2;
            }
            else break;
        }
        return nums[m];
    }
};