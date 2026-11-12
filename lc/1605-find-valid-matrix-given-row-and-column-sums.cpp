class Solution {
public:
    //m - 1 
    // vector<vector<int>> restoreMatrix(vector<int>& rs, vector<int>& cs) {
    //     int n = rs.size(), m = cs.size();
    //     vector<vector<int>> res(n, vector<int>(m));
    //     for (int j = 0; j < m; j++) {
    //         //for each col
    //         for (int i = 0; i < n; i++) {
    //             //fill cells from to row to bottom row based on
    //             //equally dividing the col sum among num of rows (or take the leftover rowSum if its value is smaller)
    //             res[i][j] = min((cs[j] + n - i - 1) / (n - i), rs[i]);//using ceil
    //             //removing the value from
    //             rs[i] -= res[i][j];
    //             cs[j] -= res[i][j];
    //             // dbg(res);
    //         }
    //     }
    //     // dbg(rs); dbg(cs);
    //     //if row n col sums still not fulfilled
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             if (rs[i] && cs[j]) {
    //                 int mn = min(rs[i], cs[j]);
    //                 res[i][j] += mn;
    //                 rs[i] -= mn;
    //                 cs[j] -= mn;
    //             }
    //         }
    //     }
    //     // dbg(res);
    //     return res;
    // }
    //m - 2 using min value only
    vector<vector<int>> restoreMatrix(vector<int>& rs, vector<int>& cs) {
        int n = rs.size(), m = cs.size();
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rs[i] && cs[j]) {
                    int mn = min(rs[i], cs[j]);
                    res[i][j] += mn;
                    rs[i] -= mn;
                    cs[j] -= mn;
                }
            }
        }
        // dbg(res);
        return res;
    }
};