class Solution {
public:
    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& q) {
        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u'};
        vector<int> presum = {0}, res;
        for (string& s : w) {
            presum.push_back(presum.back() + 
            (set.find(s[0]) != set.end() && set.find(s.back()) != set.end()));
        }
        for (auto &i : q) res.push_back(presum[i[1] + 1] - presum[i[0]]);
        return res;
    }
};