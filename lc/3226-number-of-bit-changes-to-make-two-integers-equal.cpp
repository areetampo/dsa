class Solution {
public:
    int minChanges(int n, int k) {
        int res = 0;
        if (k > n) return -1;
        while (k) {
            if ((k & 1) == 1 && (n & 1) == 0) return -1;
            else if ((k & 1) == 0 && (n & 1) == 1) res++;
            n >>= 1;
            k >>= 1;
        }
        return res + __builtin_popcount(n);
    }
};