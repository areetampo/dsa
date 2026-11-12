class Solution {
    public int numSpecial(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        int one1InRowIdx[] = new int[n];
        int one1InColIdx[] = new int[m];
        for (int i = 0; i < n; ++i) {
            int cntOf1 = 0;
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1) {
                    one1InRowIdx[i] = j;
                    if (++cntOf1 > 1) break;
                }
            }
            if (cntOf1 != 1) one1InRowIdx[i] = -1;
        }
        for (int j = 0; j < m; ++j) {
            int cntOf1 = 0;
            for (int i = 0; i < n; ++i) {
                if (mat[i][j] == 1) {
                    one1InColIdx[j] = i;
                    if (++cntOf1 > 1) break;
                }
            }
            if (cntOf1 != 1) one1InColIdx[j] = -1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (one1InRowIdx[i] != -1) {
                if (one1InColIdx[one1InRowIdx[i]] != -1) ans++;
            }
        }
        return ans;
    }
}