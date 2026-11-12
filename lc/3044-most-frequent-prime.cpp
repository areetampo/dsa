class Solution {
public:
    unordered_set<int> p;
    bool isPrime(int x) {
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) return 0;
        }
        return 1;
    }
    void init() {
        if (p.size()) return;
        for (int i = 11; i < 1e7; ++i) {
            if (isPrime(i)) p.insert(i);
        }
    }
    void dfs(int i, int j, int x, vector<vector<int>>& g, unordered_map<int, int>& mp, int n, int m, string s) {
        if (isPrime(x)) {
            ++mp[x]; //cout << x << " ";
        }
        x *= 10;
        if (s == "nw") if (0 <= i - 1 && 0 <= j - 1) dfs(i - 1, j - 1, x + g[i - 1][j - 1], g, mp, n, m, s);
        if (s == "n") if (0 <= i - 1) dfs(i - 1, j, x + g[i - 1][j], g, mp, n, m, s);
        if (s == "ne") if (0 <= i - 1 && j + 1 < m) dfs(i - 1, j + 1, x + g[i - 1][j + 1], g, mp, n, m, s);
        if (s == "w") if (0 <= j - 1) dfs(i, j - 1, x + g[i][j - 1], g, mp, n, m, s);
        if (s == "e") if (j + 1 < m) dfs(i, j + 1, x + g[i][j + 1], g, mp, n, m, s);
        if (s == "sw") if (i + 1 < n && 0 <= j - 1) dfs(i + 1, j - 1, x + g[i + 1][j - 1], g, mp, n, m, s);
        if (s == "s") if (i + 1 < n) dfs(i + 1, j, x + g[i + 1][j], g, mp, n, m, s);
        if (s == "se") if (i + 1 < n && j + 1 < m) dfs(i + 1, j + 1, x + g[i + 1][j + 1], g, mp, n, m, s);
    }
    int mostFrequentPrime(vector<vector<int>>& g) {
        // init();
        int n = g.size(), m = g[0].size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x = g[i][j];//single digit nums not needed
                x *= 10;
                if (0 <= i - 1 && 0 <= j - 1) dfs(i - 1, j - 1, x + g[i - 1][j - 1], g, mp, n, m, "nw");
                if (0 <= i - 1) dfs(i - 1, j, x + g[i - 1][j], g, mp, n, m, "n");
                if (0 <= i - 1 && j + 1 < m) dfs(i - 1, j + 1, x + g[i - 1][j + 1], g, mp, n, m, "ne");
                if (0 <= j - 1) dfs(i, j - 1, x + g[i][j - 1], g, mp, n, m, "w");
                if (j + 1 < m) dfs(i, j + 1, x + g[i][j + 1], g, mp, n, m, "e");
                if (i + 1 < n && 0 <= j - 1) dfs(i + 1, j - 1, x + g[i + 1][j - 1], g, mp, n, m, "sw");
                if (i + 1 < n) dfs(i + 1, j, x + g[i + 1][j], g, mp, n, m, "s");
                if (i + 1 < n && j + 1 < m) dfs(i + 1, j + 1, x + g[i + 1][j + 1], g, mp, n, m, "se");
            }
        } cout << endl;
        int res = -1; mp[-1] = 0;
        for (auto i = mp.begin(); i != mp.end(); ++i) {
            // cout << i->first << " " << i->second << endl;
            if (i->second > mp[res]) res = i->first;
            else if (i->second == mp[res]) res = max(res, i->first);
        }
        return res;
    }
};