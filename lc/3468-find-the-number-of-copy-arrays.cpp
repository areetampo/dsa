class Solution {
public:
    int countArrays(vector<int>& orig, vector<vector<int>>& bounds) {
        int n = orig.size(), s = bounds[0][0] - orig[0],
            e = bounds[0][1] - orig[0];
        // dbg(orig);
        // dbg(bounds);
        // dbg(s, e);
        for (int i = 1; i < n; i++) {
            s = max(orig[i] + s, bounds[i][0]) - orig[i];
            e = min(orig[i] + e, bounds[i][1]) - orig[i];
            // dbg(s, e);
        }
        if (s > e)
            return 0;
        return e - s + 1;
    }
};