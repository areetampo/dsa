class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
        vector<vector<int>> res;
        int i = 0, j = 0, n = s1.size(), m = s2.size();
        while (i < n && j < m) {
            int t1 = s1[i][0], v1 = s1[i][1], t2 = s2[j][0], v2 = s2[j][1];
            if (t1 == t2) {
                res.push_back({t1, v1 + v2});
                i++, j++;
            } else if (t1 > t2) {
                res.push_back({t2, v1 + v2});
                j++;
            } else {
                res.push_back({t1, v1 + v2});
                i++;
            }
        }
        res.insert(res.end(), s1.begin() + i, s1.end());
        res.insert(res.end(), s2.begin() + j, s2.end());
        return res;
    }
};