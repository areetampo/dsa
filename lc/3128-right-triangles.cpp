class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& g) {
        long long res = 0;
    vector<int> r;
    vector<int> c;
    for (int i = 0; i < g.size(); ++i) {
        int s = 0;
        for(int j : g[i]) s += j;
        r.push_back(s);
    }
    for (int i = 0; i < g[0].size(); ++i) {
        int s = 0;
        for (int j = 0; j < g.size(); ++j) s += g[j][i];
        c.push_back(s);
    }
     for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g[0].size(); ++j) {
            if (g[i][j] && r[i] > 1 && c[j] > 1) {
                                // cout << i << " " << j << " " << r[i] << " "<< c[j] << endl;

                res += (r[i] - 1) * (c[j] - 1);
            }
        }
    }
    return res;
    }
};