class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int m = nums[0], m1 = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] >= m) {
                m1 = m;
                m = nums[i];
            }
            else m1 = Math.max(m1, nums[i]);
        }
        return (m - 1) * (m1 - 1);
    }
}