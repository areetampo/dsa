class Solution {
public:
    // note: 2 or more recursion paths lead to same result doesnt mean all should be counted
    // skipping order should not result in a path, only the choosing of indices should
    int mod = 1e9 + 7, dp[101][101][101];
    string a, b, t;
    int dfs(int i, int j, int k) {
        if (k == t.size()) return i && j; // i,j >0 means at least 1 char from both a,b taken
        if (i == a.size() && j == b.size()) return 0;
        if (dp[i][j][k] != -1) return dp[i][j][k];

        long long res = 0;

        for (int x = i; x < a.size(); x++)
            if (a[x] == t[k])
                res = (res + dfs(x + 1, j, k + 1)) % mod;

        for (int y = j; y < b.size(); y++)
            if (b[y] == t[k])
                res = (res + dfs(i, y + 1, k + 1)) % mod;

        return dp[i][j][k] = res;
    }
    int interleaveCharacters(string w1, string w2, string tg) {
        a = w1, b = w2, t = tg;
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, 0);
    }
};