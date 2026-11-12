class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] ans = {-1, -1};
        int s = 0, e = nums.length-1, m = -1;

        //finding lower bound
        while (s <= e) {
            m = s + (e-s)/2;
            if (target < nums[m]) e = m-1;
            else if (target == nums[m]) {
                ans[0] = m;
                e = m-1;
            }
            else s = m+1;
        }
        //finding upper bound
        s = 0; e = nums.length-1; m = -1;
        while (s <= e) {
            m = s + (e-s)/2;
            if (target < nums[m]) e = m-1;
            else if (target == nums[m]) {
                ans[1] = m;
                s = m+1;
            }
            else s = m+1;
        }
        return ans;
    }
};