class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& v) {
        vector<int> res;
        for (int i = 0; i < v.size(); i++) {
            res.push_back(v[(i + v[i] + 100*(v.size())) % v.size()]);
        }
        return res;
    }
};