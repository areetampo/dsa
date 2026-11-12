class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& v) {
        int i = 0, n = v.size(), j = n - 1;
        while (i + 1 < n && v[i] <= v[i + 1]) i++;
        while (j - 1 >= 0 && v[j - 1] <= v[j]) j--;
        if (i >= j) return 0;//no deletion needed
        int l = i, r = n - 1;
        int res = min(n - 1 - i, j);
        while (r >= j && l >= 0) {
            if (v[l] > v[r]) l--;
            else r--;
            res = min(res, r - l);
        }
        // cout << i << " " << j << " " << l << " " << r << "\n";
        return res;

    }
};