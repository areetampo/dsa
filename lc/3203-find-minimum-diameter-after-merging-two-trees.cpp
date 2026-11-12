class Solution {
public:
    vector<vector<int>> makeGraph(vector<vector<int>>& e) {
        int sz = e.size() + 1;
        vector<vector<int>> g(sz);
        for (auto &i : e) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        return g;
    }
    int global_diameter; vector<bool> vis;
    int dfs(vector<vector<int>>& g, int curr) {
        // cout << curr << "\n";
        vis[curr] = 1;
        int mx_ht = 0, second_mx_ht = 0;
        for (int &i : g[curr]) {
            if (vis[i] == 1) continue;
            int ht = dfs(g, i);
            if (ht >= mx_ht) second_mx_ht = mx_ht, mx_ht = ht;
            else second_mx_ht = max(second_mx_ht, ht);
        }
        global_diameter = max(global_diameter, mx_ht + second_mx_ht);
        return 1 + mx_ht;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& e1, vector<vector<int>>& e2) {
        vector<vector<int>> g1 = makeGraph(e1), g2 = makeGraph(e2);
        vis.resize(g1.size(), 0);
        global_diameter = 0;
        dfs(g1, 0);
        int d1 = global_diameter;
        vis = vector<bool>(g2.size(), 0);
        global_diameter = 0;
        // cout << "...\n";
        dfs(g2, 0);
        int d2 = global_diameter;
        // cout << d1 << " " << d2 << "\n";
        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
};