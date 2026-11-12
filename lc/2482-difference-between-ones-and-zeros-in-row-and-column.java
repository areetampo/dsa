class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[] rowOnes = new int[n];
        int[] colOnes = new int[m];
        for (int i = 0; i < n; ++i) {
            for (int el : grid[i]) {
                rowOnes[i] += el;
            }
        }
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                colOnes[j] += grid[i][j];
            }
        }
        int[][] diff = new int[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                diff[i][j] = 2*rowOnes[i] + 2*colOnes[j] - m - n; 
            }
        }
        return diff;
    }
}