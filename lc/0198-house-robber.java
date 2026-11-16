class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 1) return nums[0];
        if (n == 2) return Math.max(nums[0], nums[1]);
        int[] dp = new int[n+1];
        //BCs
        dp[0] = 0; dp[1] = nums[0];
        //O(n) tabulation
        for (int i = 2; i <= n; i++) {
            dp[i] = Math.max(dp[i-2] + nums[i-1], dp[i-1]);
        }
        return dp[n];
    }
}