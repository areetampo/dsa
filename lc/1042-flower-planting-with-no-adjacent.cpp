class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& p) {
        vector<vector<int>> g(n + 1);//1 based indexing
        for (auto i : p) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        vector<int> res(n, 0);//acts as vis as well
        for (int i = 1; i <= n; ++i) {
            if (!res[i - 1]) {
                vector<int> marked(5, 0);
                for (int nbr : g[i]) {
                    if (res[nbr - 1]) marked[res[nbr - 1]] = 1;
                }
                for (int k = 1; k < 5; k++) if (!marked[k]) res[i - 1] = k;
            }
        }
        return res;
    }
};