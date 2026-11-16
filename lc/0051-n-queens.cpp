class Solution {
public:
    int n;
    vector<vector<int>> v;
    vector<vector<string>> res;
    bool isValid(int i, int j) {
        for (int x = 0; x < n; ++x)
            if (x != j && v[i][x] || x != i && v[x][j]) return 0;
        //always placing at next row so no need to check below rows since no queens there
        for (int x = i - 1, y = j - 1; x >= 0 && y >= 0; --x, --y)
            if (v[x][y]) return 0;
        for (int x = i - 1, y = j + 1; x >= 0 && y < n; --x, ++y)
            if (v[x][y]) return 0;
        return 1;
    }
    void dfs(int i) {
        if (i == n) {
            vector<string> t;
            for (int x = 0; x < n; ++x) {
                string s = "";
                for (int y = 0; y < n; ++y) {
                    if (v[x][y]) s += "Q";
                    else s += ".";
                }
                t.push_back(s);
            }
            res.push_back(t);
            return;
        }
        int res = 0;
        for (int j = 0; j < n; ++j) {
            v[i][j] = 1;
            if (isValid(i, j)) dfs(i + 1);
            v[i][j] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int N) {
        n = N;
        v = vector<vector<int>>(n, vector<int>(n, 0));
        res = vector<vector<string>>();
        dfs(0);
        return res;
    }
};