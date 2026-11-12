class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        int[][] dp = new int[n][m];
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = Math.max(ans, dfs(i, j, n, m, matrix, dp, ans));
            }
        }
        return ans;
    }
    private static int dfs(int i, int j, int n, int m, int[][] matrix, int[][] dp, int ans) {
        if (dp[i][j] != 0) return dp[i][j];
        int a = 0, b = 0, c = 0, d = 0; 
        if (isValid(i-1, j, n, m) && matrix[i-1][j] > matrix[i][j]) {
            a = dfs(i-1, j, n, m, matrix, dp, ans);
        }
        if (isValid(i+1, j, n, m) && matrix[i+1][j] > matrix[i][j]) {
            b = dfs(i+1, j, n, m, matrix, dp, ans);
        }
        if (isValid(i, j-1, n, m) && matrix[i][j-1] > matrix[i][j]) {
            c = dfs(i, j-1, n, m, matrix, dp, ans);
        }
        if (isValid(i, j+1, n, m) && matrix[i][j+1] > matrix[i][j]) {
            d = dfs(i, j+1, n, m, matrix, dp, ans);
        }
        return dp[i][j] = 1 + Math.max(Math.max(a, b), Math.max(c, d));
    }
    private static boolean isValid(int i, int j, int n, int m) {
        return 0 <= i && i < n && 0 <= j && j < m;
    }
}