class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        int colStart = 0, colEnd = m-1, colMid = -1;
        vector<int> res(2, -1);
        while (colStart <= colEnd) {
            colMid = (colStart + colEnd) >> 1;
            int row = 0;//row of max el in col
            for (int i = 0; i < n; ++i) {
                if (v[i][colMid] > v[row][colMid]) row = i;
            }
            cout << row << endl;
            if (colMid == 0 || colMid == m - 1 || 
                v[row][colMid - 1] < v[row][colMid] && v[row][colMid] > v[row][colMid + 1]) {
                res[0] = row; res[1] = colMid; break;
            } 
            // if (v[row][colMid - 1] < v[row][colMid]) colStart = colMid; stuck
            if (v[row][colMid] < v[row][colMid + 1]) colStart = colMid + 1;
            else colEnd = colMid;
        }
        return res;
    }
};