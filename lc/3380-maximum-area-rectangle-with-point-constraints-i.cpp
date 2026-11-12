class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& p) {
        int res = -1, n = p.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        vector<vector<int>> v = {p[i], p[j], p[k], p[l]};
                        sort(v.begin(), v.end());
                        if (v[0][0] != v[1][0] || v[2][0] != v[3][0] ||
                            v[0][1] != v[2][1] || v[1][1] != v[3][1]) continue;
                        for (int m = 0; m < n; m++) {
                            if (m == i || m == j || m == k || m == l) continue;
                            if (p[m][0] >= v[0][0] && p[m][0] <= v[2][0] &&
                                p[m][1] >= v[0][1] && p[m][1] <= v[1][1]) {
                                    // cout << 1;
                                    goto continue_outer_loop;
                            }
                        }
                        // for (auto &x : v) cout << x[0] << " " << x[1] << "\n";
                        res = max(res, (v[2][0] - v[0][0]) * (v[1][1] - v[0][1]));
                        continue_outer_loop:
                    }
                }
            }
        }
        return res;
    }
};