class Solution {
public:
    int trap(vector<int>& v) {
        int l = 0, r = v.size() - 1, left_max = v[0], right_max = v[v.size() - 1], res = 0;
        while (l < r) {
            if (left_max < right_max) {
                l++;
                res += max(0, left_max - v[l]);
                left_max = max(left_max, v[l]);
            } else {
                r--;
                res += max(0, right_max - v[r]);
                right_max = max(right_max, v[r]);
            }
        }
        return res;
    }
};