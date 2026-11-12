class Solution {
    public static class Cell {//to store each grid cell's location
        int row; int col;
        Cell(int row, int col) {
            this.row = row; this.col = col;
        }
    }
    static boolean[][] visit;//for disjoint island segments
    public int maxAreaOfIsland(int[][] grid) {
        visit = new boolean[grid.length][grid[0].length];
        int maxArea = 0;//ans
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (!visit[i][j] && grid[i][j] == 1) {
                    islandArea = 0;//each time for a new directionally disjoint island segment of graph
                    dfs(new Cell(i, j), grid);
                    maxArea = Math.max(maxArea, islandArea);//updating maxArea 
                }
            }
        }
        return maxArea;
    }
    static int islandArea;//area of disjoint graph segment (island)
    public static void dfs(Cell curr, int[][] grid) {
        visit[curr.row][curr.col] = true;//mark the visited cell true
        islandArea++;//update area of island segment
        //go in dfs of directional neighbours that aren't visited and of course != 0
        if (0 < curr.row && !visit[curr.row - 1][curr.col] && grid[curr.row - 1][curr.col] != 0) 
        dfs(new Cell(curr.row - 1, curr.col), grid);
        if (curr.row < grid.length-1 && !visit[curr.row + 1][curr.col] && grid[curr.row + 1][curr.col] != 0) 
        dfs(new Cell(curr.row + 1, curr.col), grid);
        if (0 < curr.col && !visit[curr.row][curr.col - 1] && grid[curr.row][curr.col - 1] != 0) 
        dfs(new Cell(curr.row, curr.col - 1), grid);
        if (curr.col < grid[0].length - 1 && !visit[curr.row][curr.col + 1] && grid[curr.row][curr.col + 1] != 0) 
        dfs(new Cell(curr.row, curr.col + 1), grid);
    }
}