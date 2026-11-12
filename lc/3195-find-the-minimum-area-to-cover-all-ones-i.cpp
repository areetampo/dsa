class Solution {
public:
    int minimumArea(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        int t = -1, b = -1, l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            for (int &j : g[i]) {
                if (j) {
                    t = i;
                    break;
                }
            }
            if (t != -1) break;
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (g[i][j]) {
                    l = j;
                    break;
                }
            }
            if (l != -1) break;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int &j : g[i]) {
                if (j) {
                    b = i;
                    break;
                }
            }
            if (b != -1) break;
        }
        for (int j = m - 1; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                if (g[i][j]) {
                    r = j;
                    break;
                }
            }
            if (r != -1) break;
        }
        cout << t << " " <<b << " " << l << " " << r;
        return (b - t + 1) * (r - l + 1);
    }
};