class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int t = -1;//temp for swaps

        //transpose
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }

        //swap horizontally 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n/2; j++) {
                t = matrix[i][j];
                matrix[i][j] = matrix[i][n-1-j];
                matrix[i][n-1-j] = t;
            }
        }
    }
}