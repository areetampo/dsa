class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        // n = length
        // s = first val
        // m = max abs diff of 2 adj
        if (n == 1) return s;
        // eg n = 6, s = 3, m = 5
        // 1 2 3 4  5  6
        // 3 8 7 12 11 16
        // max at even pos
        return ((long long)s + m) + ((long long)m - 1) * (n / 2 - 1);
    }
};