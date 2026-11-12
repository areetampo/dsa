class Solution {
public:
    vector<string> createGrid(int n, int m, int k) {
        // 1 <= k <= 4
        map<int, vector<vector<string>>> templates = {
            {1, {{"."}}},
            {2, {{"..", ".."}}},
            {3, {{"..", "..", ".."}, {"...", "..."}}},
            {4, {{"..", "..", "..", ".."}, {"....", "...."}, {"..#", "...", "#.."}}}
        };
        for (const auto& t : templates[k]) {
            int r = t.size(), c = t[0].size();
            if (r > n || c > m)  continue;
            vector<string> res(n, string(m, '#'));
            for (int i = 0; i < r; ++i)
                for (int j = 0; j < c; ++j)
                    res[i][j] = t[i][j];
            for (int i = r; i < n; ++i)
                res[i][c - 1] = '.';
            for (int j = c; j < m; ++j)
                res[n - 1][j] = '.';
            return res;
        }
        return {};
    }
};