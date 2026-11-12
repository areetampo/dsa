class Solution {
    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        //1D dp
        int[] dp = new int[amount + 1];

        //BCs
        //only 0 amount reachable by taking 0 coins
        for (int j = 1; j <= amount; j++) dp[j] = -1;

        //tabulation    
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i-1] <= j) {
                    if (dp[j-coins[i-1]] == -1) dp[j] = dp[j]; //stays same
                    else if (dp[j] == -1) dp[j] = 1 + dp[j-coins[i-1]];
                    else dp[j] = Math.min(1 + dp[j - coins[i-1]], dp[j]);
                } 
                else dp[j] = dp[j];//stays same
            }
        } 

        return dp[amount];
    }
} 
//2D dp
    // int[][] dp = new int[n + 1][amount + 1];

    // //BCs
    // //i = 0 -> no coins -> only 0 amount makeable with 0 coins -> [0][0] = 0 and [0][i != 0] = -1
    // for (int j = 1; j <= amount; j++) dp[0][j] = -1;
    // //j = 0 -> 0 amount -> makebale by taking 0 coins irrespective of coins.length

    // //tabulation    
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= amount; j++) {
    //         if (coins[i-1] <= j) {
    //             // if (dp[i-1][j] == -1 && dp[i][j-coins[i-1]] == -1) dp[i][j] = -1;
    //             if (dp[i][j-coins[i-1]] == -1) dp[i][j] = dp[i-1][j]; //inculcates above condition
    //             else if (dp[i-1][j] == -1) dp[i][j] = 1 + dp[i][j-coins[i-1]];
    //             else dp[i][j] = Math.min(1 + dp[i][j - coins[i-1]], dp[i-1][j]);
    //         } 
    //         else dp[i][j] = dp[i-1][j];
    //     }
    // } 

    // return dp[n][amount];