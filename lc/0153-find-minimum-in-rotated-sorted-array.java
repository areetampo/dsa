class Solution {
    public int findMin(int[] nums) {
        int s = 0; int e = nums.length - 1;
        int mid = -1;

        while (true) {
            if (nums[s] <= nums[e]) return nums[s];
            mid = s + (e-s)/2;
            if (nums[s] <= nums[mid]) s = mid + 1;
            else e = mid;
        }
    }
}