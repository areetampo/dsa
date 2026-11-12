class Solution {
public:
    int singleNumber(vector<int>& v) {
        sort(v.begin(), v.end());
        int lo = 0, hi = v.size() - 1, n = v.size();
        if (n == 1) return v[0];
        while (lo <= hi) {
            int m = lo + (hi - lo) / 2;
            //m is the unique element
            if (m == 0 || m == n - 1 || v[m - 1] != v[m] && v[m] != v[m + 1]) return v[m];
            //m is the left element of 3 batch -> m + 2 is last of batch
            if (v[m - 1] != v[m]) {
                int len = m + 2 + 1;
                if (len % 3 == 0) lo = m + 3;
                else hi = m - 1;
            }
            //m is the mid element of 3 batch -> m + 1 is last of batch
            if (v[m - 1] == v[m] && v[m] == v[m + 1]) {
                int len = m + 1 + 1;
                if (len % 3 == 0) lo = m + 2;
                else hi = m - 2;
            }
            //m is the right element of 3 batch -> m is last of batch
            if (v[m] != v[m + 1]) {
                int len = m + 1;
                if (len % 3 == 0) lo = m + 1;
                else hi = m - 3;
            }
        }
        return -1;
    }
};