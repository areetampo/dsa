class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int n = v.size(), m = v[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            if (t == v[i][j]) return 1;
            if (t < v[i][j]) --j;
            else ++i;
        }
        if (i == n || j == -1) return 0;
        while (i < n) {
            if (v[i++][j] == t) return 1;
        }
        while (j >= 0) {
            if (v[i][j--] == t) return 1;
        }
        return 0;
    }
};