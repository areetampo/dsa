class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& supp) {
        unordered_set<string> sup(supp.begin(), supp.end());
        unordered_set<string> made;
        unordered_set<string> r(rec.begin(), rec.end());
        unordered_map<string, vector<string>> g;
        unordered_map<string, int> indeg;
        int n = rec.size();
        for (int i = 0; i < n; i++) {
            for (string& j : ing[i]) {
                g[j].push_back(rec[i]);
                indeg[rec[i]]++;
                indeg[j] += 0;
            }
        }
        queue<string> q;
        for (auto& [u, v] : indeg) if (v == 0) q.push(u);
        vector<string> res;
        while (!q.empty()) {
            string top = q.front(); q.pop();\
            // cout << top << " ";
            if (r.find(top) != r.end()) made.insert(top), res.push_back(top);
            if (made.find(top) == made.end() && sup.find(top) == sup.end()) continue;
            for (string& ng : g[top]) {
                if (--indeg[ng] == 0) q.push(ng);
                // cout << ng << " " << indeg[ng] << "\n";
            }
        }
        return res;
    }
};