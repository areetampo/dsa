class Solution {
public:
    vector<vector<int>> res;
    void dfs(int k, int n, vector<int>& t) {
        if (k == 0 && n == 0) {
            vector<int> x(t.begin(), t.end());
            res.push_back(t);
            return;
        }
        if (k < 0 || n < 0) return;
        for (int i = 1; i <= 9; i++) {
            if (t.size() && t[t.size() - 1] >= i) continue;
            t.push_back(i);
            dfs(k - 1, n - i, t);
            t.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        res = {};
        vector<int> t;
        dfs(k, n, t);
        return res;
    }
};