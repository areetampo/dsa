class Solution {
    public int maxProductDifference(int[] nums) {
        int a = nums[0], b = 0, c = nums[0], d = 10001;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] >= a) {
                b = a;
                a = nums[i];
            }
            else b = Math.max(b, nums[i]);
            if (nums[i] <= c) {
                d = c;
                c = nums[i];
            }
            else d = Math.min(d, nums[i]);
        }
        return a * b - c * d;
    }
}