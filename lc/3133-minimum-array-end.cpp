class Solution {
public:
    long long minEnd(int n, long long x) {
        long long i = (n - 1) << 1, x_bit = -1;
        while (i) if ((x & (1ll << ++x_bit)) == 0) x |= ((i >>= 1) & 1) << x_bit;
        return x;
    }
};