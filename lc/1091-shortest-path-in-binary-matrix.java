class Solution {
    private class Cell {
        int x; 
        int y;
        Cell(int _x, int _y) {
            x = _x;
            y = _y;
        }
    }
    public int shortestPathBinaryMatrix(int[][] grid) {
        if (grid[0][0] != 0) return -1;//edge case
        int n = grid.length;

        int[][] helper = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

        boolean[][] vis = new boolean[n][n];
        Queue<Cell> bfs = new LinkedList<>();   
        bfs.add(new Cell(0, 0));
        vis[0][0] = true;
        bfs.add(null);

        int ans = 1;
        
        while (!bfs.isEmpty()) {
            Cell peek = bfs.remove();
            if (peek == null) {
                if (bfs.isEmpty()) return -1;
                bfs.add(null);
                ans++;
            }
            else if (peek.x == n-1 && peek.y == n-1) break;
            else {
                int newX = -1, newY = -1;
                for (int i = 0; i < 8; i++) {
                    newX = peek.x + helper[i][0];
                    newY = peek.y + helper[i][1];
                    if (isValid(newX, newY, n, grid, vis)) {
                        bfs.add(new Cell(newX, newY));
                        vis[newX][newY] = true;
                    }
                }
            }
        }
        return ans;
    }
    private boolean isValid(int x, int y, int n, int[][] grid, boolean[][] vis) {
        return 0 <= x && x < n && 0 <= y && y < n && grid[x][y] == 0 && !vis[x][y];
    }
}