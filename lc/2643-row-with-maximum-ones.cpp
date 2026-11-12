class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        for (int i = 0; i < n; ++i) sort(v[i].begin(), v[i].end());
        int i = 0, j = m - 1, thatRow = 0;
        while (i < n && j >= 0) {
            if (!v[i][j]) ++i;
            else { thatRow = i; while (j >= 0 && v[i][j]) {--j;}}
        }
        return {thatRow, m - j - 1};
    }
};