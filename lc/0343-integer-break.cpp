class Solution {
public:
    int integerBreak(int n) {
        if (n == 1 || n == 2) return 1;
        if (n == 3) return 2;
        int r = n % 3, q = n / 3;
        if (!r) return pow(3, q);
        if (r == 1) return pow(3, q - 1) * 4;
        return pow(3, q) * 2;
    }
};