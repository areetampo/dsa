class Solution {
public:
    long long findKthSmallest(vector<int>& v, int k) {
        // inc-exc principle
        int n = v.size();
        vector<long long> LCM(1 << n); // 2^15

        for (int i = 1; i < (1 << n); i++) { // no 0: ignore empty subset
            LCM[i] = 1;
            for (int j = i, idx = 0; j; j >>= 1, idx++)
                if (j & 1) LCM[i] = lcm(LCM[i], v[idx]);
        }

        // lcm(a,b) >= max(a,b)​ always true so any denominations > k auto excluded
        // bin srch to find res so total k vals including it

        long long mn = *min_element(v.begin(), v.end()),
                lo = mn, hi = mn * k;
        while (lo <= hi) {
            auto m = lo + (hi - lo) / 2, x = 0ll;
            for (int i = 1; i < (1 << n); i++)
                x += m / LCM[i] * (__builtin_popcount(i) & 1 ? 1 : -1);

            // if m is the answer theres x values (formed by taking the denominations)
            if (x < k) lo = m + 1;
            else hi = m - 1;
        }

        return lo;
    }
};