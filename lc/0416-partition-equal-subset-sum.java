class Solution {
    public boolean canPartition(int[] nums) {//0-1 Knapsack Variation
        int n = nums.length;
        int sum = 0;
        for (int el : nums) sum += el;//given el +ve 
        if (sum % 2 == 1) return false;//odd sum so sum/2 partition never possible
        sum /= 2;

        boolean dp[] = new boolean[sum+1];
        //BCs
        dp[0] = true;

        //tabulation
        for (int val : nums) {//0 -> n-1 
            for (int j = sum; j > 0; j--) {//reverse
                if (val <= j) 
                dp[j] = dp[j-val] || dp[j];
                //else stays dp[j] only
            }
        }

        return dp[sum];

    }
}

//2D dp

// boolean dp[][] = new boolean[n+1][sum + 1];
// //BCs
// //i = 0 -> 0 array length -> only j = 0 sum reachable (true);
// //j = 0 -> have choice to take no array elements to make sum 0 (all j = 0 true)
// for (int i = 0; i <= n; i++) dp[i][0] = true;

// //tabulation
// for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= sum; j++) {
//         int val = nums[i-1];
//         if (val <= j) 
//         dp[i][j] = dp[i-1][j-val] || dp[i-1][j];
//         else dp[i][j] = dp[i-1][j];
//     }
// }

// return dp[n][sum];