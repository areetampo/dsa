class Solution {
    public int minPathSum(int[][] grid) {
        int n = grid.length; int m = grid[0].length;
        int[][] dp = new int[n][m];
        //BCs
        dp[n-1][m-1] = grid[n-1][m-1];
        for (int i = n - 2; i >= 0; i--) dp[i][m-1] = grid[i][m-1] + dp[i+1][m-1];
        for (int j = m - 2; j >= 0; j--) dp[n-1][j] = grid[n-1][j] + dp[n-1][j+1];
        //tabulation (bottom-up + right-left filling) 
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                dp[i][j] = grid[i][j] + Math.min(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
}
//RECURSION - TLE
// return help(0, 0, 0, grid);
// public static int help(int row, int col, int sum, int[][] grid) {
//     if (row == grid.length-1 && col == grid[0].length-1) {
//         return sum + grid[row][col];
//     } 
//     if (row == grid.length-1) {
//         return help(row, col+1, sum + grid[row][col], grid);
//     }
//     else if (col == grid[0].length-1) {
//         return help(row+1, col, sum + grid[row][col], grid);
//     }
//     else {
//         return Math.min(help(row+1, col, sum + grid[row][col], grid), help(row, col+1, sum + grid[row][col], grid));
//     }
// }