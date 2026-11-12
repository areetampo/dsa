class Solution {
    public int minScoreTriangulation(int[] values) {
        int n = values.length;
        int dp[][] = new int[n][n];
        for (int x = 2; x <= n-1; x++) {
            for (int i = 0; i <= n-1-x; i++) {
                int j = i + x;
                int min = Integer.MAX_VALUE;
                for (int k = i+1; k < j; k++) {
                    //[i][j] line is marked, impact of [i][k] + [k][j] req
                    min = Math.min(min, dp[i][k] + dp[k][j] + values[i]*values[k]*values[j]);
                }
                if (min != Integer.MAX_VALUE)
                dp[i][j] = min;
            }
        }
        return dp[0][n-1];
    }
}