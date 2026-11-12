class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& v1, vector<vector<int>>& v2) {
        int i = 0, j = 0;
        vector<vector<int>> res;
        while (i < v1.size() && j < v2.size()) {
            int id1 = v1[i][0], val1 = v1[i][1], id2 = v2[j][0], val2 = v2[j][1];
            if (id1 == id2) {
                res.push_back({id1, val1 + val2}), i++, j++;
            } else if (id1 < id2) {
                res.push_back({id1, val1}), i++;
            } else {
                res.push_back({id2, val2}), j++;
            }
        }
        res.insert(res.end(), v1.begin() + i, v1.end());
        res.insert(res.end(), v2.begin() + j, v2.end());
        return res;
    }
};