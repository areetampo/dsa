class Solution {
public:
    int subarraySum(vector<int>& v) {
        int res = 0;
        for (int i = 0; i < v.size(); i++) {
            for (int j = max(0, i - v[i]); j <= i; j++) {
                res += v[j];
            }
        }
        return res;
    }
};