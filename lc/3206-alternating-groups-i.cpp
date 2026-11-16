class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& v, int k = 3) {
        int res = 0, n = v.size(), j = 0, i = 0;
        while (1) {
            if (v[j % n] != v[(j + 1) % n]) j++;
            else {
                j++;
                i = j;
            }
            if (i >= n || j >= n + k - 1) break;
            if (j < n && j - i + 1 >= k) res++;
            else if (j >= n && (j % n) + 1 + n - i >= k) res++;
            // cout << i << " " << j << " " << res << endl;
        }
        return res;
    }
};