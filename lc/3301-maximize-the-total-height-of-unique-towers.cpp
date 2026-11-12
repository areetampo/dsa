class Solution {
public:
    long long maximumTotalSum(vector<int>& h) {
        sort(h.begin(), h.end());
        long long res = h[h.size() - 1];
        for (int i = h.size() - 2; i >= 0; i--) {
            h[i] = min(h[i], h[i + 1]);
            if (h[i] == h[i + 1] && --h[i] == 0) return -1;
            res += h[i];
        }
        return res;
    }
};