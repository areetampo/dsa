class Solution {
public:
    vector<vector<int>> g;
    unordered_set<int> group;
    void dfs(int i) {
        group.insert(i);
        for (int& nb : g[i]) {
            if (group.find(nb) == group.end()) dfs(nb);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& e) {
        g = vector<vector<int>>(n);
        group = unordered_set<int>();
        for (auto& i : e) g[i[0]].push_back(i[1]);
        dfs(k);
        vector<int> r;
        for (int i = 0; i < n; i++)
            if (group.find(i) == group.end()) r.push_back(i);
        for (int i = 0; i < n; i++)
            if (group.find(i) != group.end()) r.push_back(i);
        bool remove_group = 1;
        // if any outside node forms a edge to a node in group
        for (auto& i : e) {
            if (group.find(i[1]) != group.end() &&
                group.find(i[0]) == group.end()) {
                    remove_group = 0;
                    break;
                }
        }
        if (remove_group) r.resize(n - (int)group.size());
        return r;
    }
};