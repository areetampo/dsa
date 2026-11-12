class Solution {
public:
    void 
    dfs(unordered_set<int> &taken, stack<int> &curr, vector<int> &v, vector<vector<int>> &res) {
        if (curr.size() == v.size()) {//or = taken.size()
            stack<int> auxi;
            while (!curr.empty()) {auxi.push(curr.top()); curr.pop();}
            vector<int> ans;
            while (!auxi.empty()) {
                ans.push_back(auxi.top());
                curr.push(auxi.top());
                auxi.pop();
            }
            res.push_back(ans);
            return;
        }
        for (int i = 0; i < v.size(); ++i) {
            if (i > 0 && v[i-1] == v[i] && taken.find(i-1) == taken.end()) continue;
            if (taken.find(i) == taken.end()) {
                taken.insert(i);
                curr.push(v[i]);
                dfs(taken, curr, v, res);
                curr.pop();
                taken.erase(i);
            }
        }     
    }
    vector<vector<int>> permuteUnique(vector<int>& v) {
        sort(v.begin(), v.end());
        unordered_set<int> taken;//for idx
        stack<int> curr;
        vector<vector<int>> res;
        dfs(taken, curr, v, res);
        return res;
    }
};