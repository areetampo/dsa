class Solution {//mcm
    public int minCost(int n, int[] cuts) {
        int m = cuts.length;
        int[] cut = new int[m+2]; cut[m+1] = n;
        for (int i = 0, j = 1; i < m; ) cut[j++] = cuts[i++];
        Arrays.sort(cut);

        int dp[][] = new int[m+2][m+2];

        for (int x = 1; x <= m+1; x++) {
            for (int i = 0; i <= m+1-x; i++) {
                int j = i + x;
                int minCut = Integer.MAX_VALUE;
                for (int k = i + 1; k < j; k++) {
                    minCut = Math.min(minCut, (cut[j]-cut[i]) + dp[i][k] + dp[k][j]);
                }
                if (minCut != Integer.MAX_VALUE)//otherwise dp[i][j] stays 0
                dp[i][j] = minCut;
            }
        }
        return dp[0][m+1];
    }
}

//MEMOIZATION - MLE
// public int minCost(int n, int[] cuts) {
//     return mcm(0, n, cuts, new int[n+1][n+1]);//0 <-> n 
// }
// public static int mcm(int i, int j, int[] cuts, int[][] dp) {
//     if (i == j) return 0;
//     if (dp[i][j] != 0) return dp[i][j];
//     int ans = Integer.MAX_VALUE;
//     for (int cut : cuts) {
//         if (i < cut && cut < j) {   
//             ans = Math.min (ans, (j-i) + mcm(i, cut, cuts, dp) + mcm(cut, j, cuts, dp));//current cut cost + go in left + right 
//         }
//     }
//     return dp[i][j] = (ans != Integer.MAX_VALUE) ? ans : 0;
// }