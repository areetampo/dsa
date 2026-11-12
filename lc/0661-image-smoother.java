class Solution {
    public int[][] imageSmoother(int[][] img) {
        int n = img.length, m = img[0].length;
        int[][] ans = new int[n][m];
        int[][] help = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = compute(img, i, j, n, m, help);
            }
        }
        return ans;
    }
    private static int compute(int[][] img, int i, int j, int n, int m, int[][] help) {
        int cells = 0, val = 0;
        for (int h[] : help) {
            int I = i + h[0], J = j + h[1];
            if (0 <= I && 0 <= J && I < n && J < m) {
                cells++;
                val += img[I][J];
            }
        }
        return val/cells;
        
    }
}