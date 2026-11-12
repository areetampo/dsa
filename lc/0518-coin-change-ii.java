class Solution {
    public int change(int amount, int[] coins) {
        int[][] dp = new int[coins.length + 1][amount + 1];
        //BCs
        //0 amount (col 0) -> 0 coins will be needed irrespective of array size = 1 way
        for (int i = 0; i <= coins.length; i++) dp[i][0] = 1;
        //0 coins given (row 0) -> no possible ways to make any amount > 0 = 0 ways (initialized)
        for (int i = 1; i <= coins.length; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i-1] <= j) {
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];//total possible ways (inc + exc)
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[coins.length][amount];
    }
}