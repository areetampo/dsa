class Solution {
public:
    vector<vector<int>> g;
    int n, m, comps_num = 0, comp_size, dir[5] = {0, 1, 0, -1, 0};
    vector<int> comp_map = {0};
    void dfs(int i, int j) {
        g[i][j] = comps_num - 1;
        comp_size++;
        for (int k = 0; k < 4; k++) {
            int _i = i + dir[k], _j = j + dir[k + 1];
            if (min(_i, _j) < 0 || _i == n || _j == m || g[_i][_j] != 1) 
                continue;
            dfs(_i, _j);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        g = grid;
        n = g.size(), m = g[0].size();
        //reuse g to assign island groups as components using -ve numbers
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1) {
                    comp_size = 0;
                    dfs(i, j);
                    comps_num--;
                    comp_map.push_back(comp_size);
                }
            }
        }
        // cout << comps_num << "\n";
        // for (int &i : comp_map) cout << i << " "; cout << "\n";
        if (comp_size == n * m) return n * m;
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] < 0) continue;
                unordered_set<int> adj_islands;
                for (int k = 0; k < 4; k++) {
                    int _i = i + dir[k], _j = j + dir[k + 1];
                    if (min(_i, _j) < 0 || _i == n || _j == m) continue;
                    adj_islands.insert(g[_i][_j]);
                }
                int total_cells = 1;
                for (auto& it : adj_islands) {
                    // cout << it << " ";
                    total_cells += comp_map[-it];
                } 
                // cout << "\n";
                res = max(res, total_cells);
            }
        }
        return res;
    }
};