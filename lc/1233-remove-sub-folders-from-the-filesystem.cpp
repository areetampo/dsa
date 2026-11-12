class Solution {
public:
    vector<string> removeSubfolders(vector<string>& f) {
        vector<string> res;
        sort(f.begin(), f.end());
        for (int i = 0; i < f.size(); ) {
            res.push_back(f[i]);
            while (++i < f.size() && f[i].substr(0, res.back().size()) == res.back() && f[i][res.back().size()] == '/');
        }
        return res;
    }
};