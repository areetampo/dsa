class Solution {
public:
    int n;
    vector<vector<int>> g;
    vector<int> state;
    vector<int> res;
    bool dfs(int i) {
        // cout << i << " ";
        state[i] = 1;
        bool safe;
        for (int& neighbor : g[i]) {
            if (state[neighbor] == 1) {
                safe = 0;
            } else if (state[neighbor] == 2) {
                safe = 1;
            } else {
                safe = dfs(neighbor);
            }
            if (safe == 0) break;
        }
        //returns true if safe
        if (safe) res.push_back(i);
        state[i] = 1 + safe;
        return safe;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        g = graph;
        n = g.size();
        state = vector<int>(n, 0);//0 unvis, 1 unsafe, 2 safe
        res = vector<int>();
        for (int i = 0; i < n; i++) {
            if (state[i] == 0) dfs(i);
        }
        sort(res.begin(), res.end());
        return res;
    }
};