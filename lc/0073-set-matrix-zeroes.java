class Solution {
    public void setZeroes(int[][] matrix) {
        boolean markRow1 = false;
        boolean markCol1 = false;

        int r = matrix.length; int c = matrix[0].length;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 0) {//if a cell = 0
                    if (i == 0) markRow1 = true;
                    if (j == 0) markCol1 = true;
                    matrix[i][0] = 0;//flag its whole row to be marked 0 via putting 0 in col0 of the row
                    matrix[0][j] = 0;//flag its whole col to be marked 0 via putting 0 in row0 of the col
                }
            }
        }    

        //all [row][0] = 0 -> mark entire row = 0, start from 2nd row (idx 1) as row1 has all cols flagged to make whole row of that 0 
        //all [0][col] = 0 -> mark entire col = 0, satrt from 2nd col (idx 1) as same story
        for (int i = 1; i < r; i++) {
            if (matrix[i][0] == 0) Arrays.fill(matrix[i], 0);
        }
        for (int j = 1; j < c; j++) {
            if (matrix[0][j] == 0) 
            for (int i = 0; i < r; i++) {
                matrix[i][j] = 0;
            }
        }

        if (markRow1) Arrays.fill(matrix[0], 0);
        if (markCol1) 
        for (int i = 0; i < r; i++) matrix[i][0] = 0; 
    }
}