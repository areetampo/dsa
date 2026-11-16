class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int n = v.size(), m = v[0].size();
        int lo = 0, hi = n-1, mid = -1;
        while (lo <= hi) {
            mid = (lo + hi) >> 1;
            if (v[mid][0] <= target && target <= v[mid][m-1]) break;
            if (v[mid][0] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        if (lo > hi) return false;
        int r = mid;
        lo = 0; hi = m-1;
        while (lo <= hi) {
            mid = (lo + hi) >> 1;
            if (v[r][mid] == target) return true;
            if (v[r][mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return false;
    }
};