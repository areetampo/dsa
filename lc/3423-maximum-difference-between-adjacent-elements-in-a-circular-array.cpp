class Solution {
public:
    int maxAdjacentDistance(vector<int>& v) {
        int res = abs(v.back() - v[0]);
        for (int i = 0; i < v.size() - 1; i++) {
            res = max(res, abs(v[i] - v[i + 1]));
        }
        return res;
    }
};