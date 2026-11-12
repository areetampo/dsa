class Solution {
public:
    long long maximumTripletValue(vector<int>& a) {
        long long res = 0;
        for (int k = 0, max_i = 0, max_diff = 0; k < a.size(); k++) {
            res = max(res, 1ll * max_diff * a[k]);
            max_diff = max(max_diff, max_i - a[k]);
            max_i = max(max_i, a[k]);
        }
        return res;
    }
};