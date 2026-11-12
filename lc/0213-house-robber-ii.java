class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 1) return nums[0];
        if (n == 2) return Math.max(nums[0], nums[1]);
        // if (n == 3) return Math.max(nums[0], Math.max(nums[1], nums[2]));
        boolean[] firstHouse = new boolean[n+1];
        int[] dp = new int[n+1];
        dp[1] = nums[0];
        firstHouse[1] = true;
        for (int i = 2; i <= n; ++i) {
            dp[i] = Math.max(dp[i-2] + nums[i-1], dp[i-1]);
            if (dp[i-2] + nums[i-1] == dp[i-1]) {
                if (firstHouse[i-2] && firstHouse[i-1]) firstHouse[i] = true;
            }
            else if (dp[i-2] + nums[i-1] > dp[i-1]) {
               if (firstHouse[i-2]) firstHouse[i] = true; 
            }
            else {
                if (firstHouse[i-1]) firstHouse[i] = true;
            }
        }
        int[] dp1 = new int[n+1];
        dp1[2] = nums[1];
        for (int i = 3; i <= n; ++i) {
            dp1[i] = Math.max(dp1[i-2] + nums[i-1], dp1[i-1]);
        }
        
        if (firstHouse[n]) return Math.max(dp[n-1], dp1[n]);
        return dp1[n];
    }
}