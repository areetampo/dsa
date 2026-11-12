class Solution {
public:
    int mod = 1e9 + 7;
    int power(long long base, long long exp) {
        int r = 1;
        while (exp > 0) {
            if (exp % 2 == 1) r = (base * r) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return r;
    }
    int countGoodNumbers(long long n) {
        return ((long long)power(5, (n + 1) / 2) * power(4, n / 2)) % mod;
    }
};