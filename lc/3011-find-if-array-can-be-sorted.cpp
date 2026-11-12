class Solution {
public:
    bool canSortArray(vector<int>& v) {
        int prev_mx = 0;
        for (int i = 0, j; i < v.size(); i = j) {
            j = i;
            int curr_mx = v[i], curr_mn = v[i];
            while (j < v.size() && __builtin_popcount(v[i]) == __builtin_popcount(v[j])) {
                curr_mx = max(curr_mx, v[j]);
                curr_mn = min(curr_mn, v[j++]);
            }
            if (curr_mn < prev_mx) return 0;
            prev_mx = curr_mx;
        }
        return 1;
    }
};