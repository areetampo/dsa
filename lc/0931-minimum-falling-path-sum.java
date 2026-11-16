class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) dp[i] = matrix[0][i];
        int[] temp = new int[n];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; j++) {
                temp[j] = dp[j];
            }
            dp[0] = matrix[i][0] + Math.min(temp[0], temp[1]);
            for (int j = 1; j < n-1; ++j) dp[j] = matrix[i][j] + Math.min(temp[j-1], Math.min(temp[j], temp[j+1]));
            dp[n-1] = matrix[i][n-1]+ Math.min(temp[n-2], temp[n-1]);
        }
        int ans = Integer.MAX_VALUE;
        for (int el : dp) {
            ans = Math.min(ans, el);
        }
        return ans;
    }
}