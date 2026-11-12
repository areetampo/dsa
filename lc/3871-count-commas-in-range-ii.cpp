class Solution {
public:
    long long countCommas(long long n) {
        long long r = 0;

        for (long long i = 1e3; i <= n; i *= 10) {
            long long vals = min(n, i * 10 - 1) - i + 1,
                    digits = log10(i) + 1,
                    commas = digits / 3 - (digits % 3 == 0);
            r += vals * commas;
        }

        return r;
    }
};