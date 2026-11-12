class Solution {
    public int countPaths(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[][] dp = new int[n][m];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == 0) dp[i][j] = dfs(i, j, n, m, grid, dp);
                ans = (ans + dp[i][j]) % 1000000007;
            }
        }
        return ans;
    }
    private static int dfs(int i, int j, int n, int m, int[][] grid, int[][] dp) {
        if (dp[i][j] != 0) return dp[i][j];
        int down = 0, up = 0, right = 0, left = 0;
        if (isValid(i+1, j, n, m) && grid[i+1][j] > grid[i][j]) {
            down = dfs(i+1, j, n, m, grid, dp);
        }
        if (isValid(i-1, j, n, m) && grid[i-1][j] > grid[i][j]) {
            up = dfs(i-1, j, n, m, grid, dp);
        }
        if (isValid(i, j+1, n, m) && grid[i][j+1] > grid[i][j]) {
            right = dfs(i, j+1, n, m, grid, dp);
        }
        if (isValid(i, j-1, n, m) && grid[i][j-1] > grid[i][j]) {
            left = dfs(i, j-1, n, m, grid, dp);
        }
        return dp[i][j] = (1 + down + up + right + left) % 1000000007;//individual cell paths = 1
    }
    private static boolean isValid(int i, int j, int n, int m) {
        return 0 <= i && i < n && 0 <= j && j < m;
    }
}