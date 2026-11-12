class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<pair<int, int>>> v(n, vector<pair<int, int>>(m, { 0, 0 }));
        if (g[0][0] == 'X') v[0][0].first = 1;
        if (g[0][0] == 'Y') v[0][0].second = 1;
        int res = 0;
        for (int i = 1; i < n; i++) {
            v[i][0].first = v[i - 1][0].first;
            v[i][0].second = v[i - 1][0].second;
            if (g[i][0] == 'X') v[i][0].first += 1;
            if (g[i][0] == 'Y') v[i][0].second += 1;
            if (v[i][0].first == v[i][0].second && v[i][0].first) res++;
        }
        for (int j = 1; j < m; j++) {
            v[0][j].first = v[0][j - 1].first;
            v[0][j].second = v[0][j - 1].second;
            if (g[0][j] == 'X') v[0][j].first += 1;
            if (g[0][j] == 'Y') v[0][j].second += 1;
            if (v[0][j].first == v[0][j].second && v[0][j].first) res++;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                v[i][j].first = v[i - 1][j].first + v[i][j - 1].first - v[i - 1][j - 1].first;
                v[i][j].second = v[i - 1][j].second + v[i][j - 1].second - v[i - 1][j - 1].second;
                if (g[i][j] == 'X') v[i][j].first += 1;
                if (g[i][j] == 'Y') v[i][j].second += 1;
                if (v[i][j].first == v[i][j].second && v[i][j].first) res++;
            }
        }
        // f1(i, n) {
        //     f1(j, m) {
        //         cout << v[i][j].first << "," << v[i][j].second << "   ";
        //     }
        //     cout << endl;
        // }
        return res; 
    }
};