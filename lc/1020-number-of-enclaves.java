class Solution {
    public int numEnclaves(int[][] grid) {//O(n * m)
        //what to do?
        //find islands unconnected with boundary islands and return total number of cells in those islands
        int n = grid.length, m = grid[0].length;
        boolean[][] vis = new boolean[n][m];
        int ans = 0;

        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int val = dfs(i, j, n, m, grid, vis);
                    if (val != -1) ans += val;
                }
            }
        }
        return ans;
    }
    private static int dfs(int i, int j, int n, int m, int[][] grid, boolean[][] vis) {
        if (i == 0 || j == 0 || i == n-1 || j == m-1) return -1;
        vis[i][j] = true;
        int down = 0, up = 0, right = 0, left = 0;
        if (isValid(i+1, j, n, m, grid, vis)) {
            down = dfs(i+1, j, n, m, grid, vis);
        }
        if (isValid(i-1, j, n, m, grid, vis)) {
            up = dfs(i-1, j, n, m, grid, vis);
        }
        if (isValid(i, j+1, n, m, grid, vis)) {
            right = dfs(i, j+1, n, m, grid, vis);
        }
        if (isValid(i, j-1, n, m, grid, vis)) {
            left = dfs(i, j-1, n, m, grid, vis);
        }
        if (down == -1 || up == -1 || right == -1 || left == -1) return -1;
        return 1 + down + up + right + left;
    }
    private static boolean isValid(int i, int j, int n, int m, int[][] grid, boolean[][] vis) {
        return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1 && !vis[i][j];
    }
}