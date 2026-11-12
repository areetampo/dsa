class Solution {
    public long largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        long s = nums[0] + nums[1];
        long ans = -1;
        for (int i = 2; i < nums.length; ++i) {
            if (s > nums[i]) ans = s + nums[i];
            s += nums[i];
        }
        return ans;
    }
}