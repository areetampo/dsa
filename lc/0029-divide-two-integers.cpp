class Solution {
public:
    int divide(int n, int d) {
        long long N = n; N = abs(N);
        long long D = d; D = abs(D);
        long long res = 0;
        int i = 31;
        while (N >= D) {
            if (N >= (D << i)) {
                N -= D << i;
                res += (long long)1 << i;
            }
            i--;
            // cout << (one << i) << endl;
        }
        // cout << res;
        return (n > 0 != d > 0) ? max(-res, (long long)INT_MIN) : min((long long)INT_MAX, res);
    }
};