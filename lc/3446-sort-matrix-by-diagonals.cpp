class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& g) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[0].size(); j++) {
                m[i - j].push_back(g[i][j]);
            }
        }
        for (auto& [k, v] : m) {
            if (k >= 0) sort(v.begin(), v.end());
            else sort(v.rbegin(), v.rend());
        }
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[0].size(); j++) {
                g[i][j] = m[i - j].back();
                m[i - j].pop_back();
            }
        }
        return g;
    }
};