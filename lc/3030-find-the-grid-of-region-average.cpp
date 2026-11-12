class Solution {
public:
    bool valid(int i, int j, int r1, int r2, int c1, int c2, vector<vector<int>>& g, int t) {
        if (i - 1 >= r1) if (abs(g[i][j] - g[i-1][j]) > t) return 0;
        if (i + 1 <= r2) if (abs(g[i][j] - g[i+1][j]) > t) return 0;
        if (j - 1 >= c1) if (abs(g[i][j] - g[i][j-1]) > t) return 0;
        if (j + 1 <= c2) if (abs(g[i][j] - g[i][j+1]) > t) return 0;
        return 1;
    }
    vector<vector<int>> resultGrid(vector<vector<int>>& g, int t) {
        int n = g.size(), m = g[0].size();
        //no extra space
        //res stores a value whose bits: num of regions val belongs to (max: 9), the sum (max: 255 * 9 < 2^12 or 4096)
        //bits:                                    first 4 bits (0 to 1001(9)) (lsb)       next 11 bits
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int r1 = 0; r1 < n-2; ++r1) {
            int r2 = r1 + 2;
            for (int c1 = 0; c1 < m-2; ++c1) {
                int c2 = c1 + 2;
                int avg = 0;
                for (int i = r1; i <= r2; ++i) {
                    for (int j = c1; j <= c2; ++j) {
                        if (!valid(i, j, r1, r2, c1, c2, g, t)) { avg = -1; break; }
                        avg += g[i][j];
                    }
                    if (avg == -1) break;
                }
                if (avg == -1) continue;
                avg /= 9;
                for (int i = r1; i <= r2; ++i) for (int j = c1; j <= c2; ++j) {
                    //10000 - 1 = 1111 or 15
                    int regions = res[i][j] & ((1 << 4) - 1); ++regions;
                    //11 1s = 2^12 - 1 (msb) and there are 4 bits more in right to represent regions
                    //or 1111111111110000 = 4095 * 16 = 65520
                    int sum = res[i][j] & (((1 << 12) - 1) << 4); sum += avg << 4;
                    res[i][j] = sum | regions;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int regions = res[i][j] & ((1 << 4) - 1);
                int sum = (res[i][j] & (((1 << 12) - 1) << 4)) >> 4;
                res[i][j] = (regions) ? sum/regions : g[i][j];
            }
        }
        return res;
    }
};
//with extra space
// vector<vector<int>> resultGrid(vector<vector<int>>& g, int t) {
//     int n = g.size(), m = g[0].size();
//     vector<vector<vector<int>>> r(n, vector<vector<int>>(m, vector<int>(0)));
//     for (int r1 = 0; r1 < n-2; ++r1) {
//         int r2 = r1 + 2;
//         for (int c1 = 0; c1 < m-2; ++c1) {
//             int c2 = c1 + 2;
//             int x = 0;
//             for (int i = r1; i <= r2; ++i) {
//                 for (int j = c1; j <= c2; ++j) {
//                     if (!valid(i, j, r1, r2, c1, c2, g, t)) { x = 1; cout << i << j<< endl;break; }
//                 }
//                 if (x) break;
//             }
//             if (x) continue;
//             int avg = 0;
//             for (int i = r1; i <= r2; ++i) for (int j = c1; j <= c2; ++j) avg += g[i][j];
//             avg /= 9;
//             for (int i = r1; i <= r2; ++i) for (int j = c1; j <= c2; ++j) r[i][j].push_back(avg);
//         }
//     }
//     // for (int i = 0; i < n; ++i) {//print 
//     //     for (int j = 0; j < m; ++j) { cout << i << " " << j << ": "; for (int &x : r[i][j]) cout << x << " "; cout << ", ";}
//     //     cout << endl;
//     // }
//     vector<vector<int>> res(n, vector<int>(m, 0));
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             int avg = 0;
//             for (int &k : r[i][j]) avg += k;
//             if (r[i][j].size()) avg /= r[i][j].size();
//             res[i][j] = (r[i][j].size()) ? avg : g[i][j];
//         }
//     }
//     return res;
// }