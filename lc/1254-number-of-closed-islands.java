class Solution {
    public int closedIsland(int[][] grid) {
        int ans = 0;
        boolean[][] vis = new boolean[grid.length][grid[0].length];
        for (int i = 1; i < vis.length-1; i++) {
            for (int j = 1; j < vis[0].length-1; j++) {
                if (!vis[i][j] && grid[i][j] == 0) {
                    if (dfs(i, j, vis, grid)) 
                    ans++;
                }
            }
        }
        return ans;
    }
    public static boolean dfs(int i, int j, boolean[][] vis, int[][] grid) {
        if (i == 0 || j == 0 || i == grid.length-1 || j == grid[0].length-1) return false;
        vis[i][j] = true;
        boolean down = true, up = true, right = true, left = true;
        if (0 <= i+1 && i+1 <= grid.length-1 && !vis[i+1][j]) {
            if (grid[i+1][j] == 0) down = dfs(i+1, j, vis, grid);
            else down = true;
        }
        if (0 <= i-1 && i-1 <= grid.length-1 && !vis[i-1][j]) {
            if (grid[i-1][j] == 0) up = dfs(i-1, j, vis, grid);
            else up = true;
        }
        if (0 <= j+1 && j+1 <= grid[0].length-1 && !vis[i][j+1]) {
            if (grid[i][j+1] == 0) right = dfs(i, j+1, vis, grid);
            else right = true;
        }
        if (0 <= j-1 && j-1 <= grid[0].length-1 && !vis[i][j-1]) {
           if (grid[i][j-1] == 0) left = dfs(i, j-1, vis, grid);
            else left = true;
        }
        return down && up && right && left;
    }
}
