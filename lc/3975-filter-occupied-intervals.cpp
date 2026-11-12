class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& in, int fs, int fe) {
        sort(in.begin(), in.end());
        vector<vector<int>> res;
        for (int i = 0, j; i < in.size(); i = j + 1) {
            int x = in[i][0], mx = in[i][1];
            j = i;
            while (j + 1 < in.size() && mx + 1 >= in[j + 1][0]) {
                mx = max(mx, in[j + 1][1]);
                j++;
            }
            int a = fs <= x && x <= fe ? fe + 1 : x, 
                b = fs <= mx && mx <= fe ? fs - 1 : mx;
            if (a > b) { // [a,b] inside [fs,fe]
                // dont add
            } else if (a <= fs && fe <= b) { // [fs,fe] inside [a,b]
                // split
                res.push_back({a, fs - 1});
                res.push_back({fe + 1, b});
            } else res.push_back({a, b}); // some overlap
        }
        return res;
    }
};