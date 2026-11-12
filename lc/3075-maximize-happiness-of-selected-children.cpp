class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        int del = 0;
        long long res = 0;
        sort(h.rbegin(), h.rend());
        for (int i = 0; i < min((int)h.size(), k); ++i) {
            if (h[i] - del <= 0) break;
            res += h[i] - del;
            ++del;
        }
        return res;
    }
};