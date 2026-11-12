class Solution {
public:
    int maxFrequency(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        // dbg(v);
        int n = v.size(), res = 1;
        long long sum = 0;
        for (int i = 0, j = 1; j < n; j++) {
            sum += (long long)(v[j] - v[j - 1]) * (j - i);
            while (sum > k) {
                sum -= v[j] - v[i++];
            }
            res = max(res, j - i + 1);
            // dbg(i, j, sum, res);
        }
        return res;
    }
};