class Solution {
public:
    int countCommas(int n) {
        int r = 0;

        for (int i = 1e3; i <= n; i *= 10) {
            int vals = min(n, i * 10 - 1) - i + 1,
                digits = log10(i) + 1,
                commas = digits / 3 - (digits % 3 == 0);
            r += vals * commas;
        }

        return r;
    }
};