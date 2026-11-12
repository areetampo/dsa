class Solution {
public:
    vector<int> resultsArray(vector<int>& v, int k) {
        if (k == 1) return v;
        int cnt = 0, n = v.size();
        for (int i = 1; i < n; i++) {
            cnt = v[i - 1] + 1 == v[i] ? cnt + 1 : 0;
            // cout << cnt << "\n";
            if (i >= k - 1) v[i - (k - 1)] = cnt >= k - 1 ? v[i] : -1;
        }
        v.resize(n - k + 1);
        return v;
    }
};