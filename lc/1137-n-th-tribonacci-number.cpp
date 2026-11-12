class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1;
        if (n < 3) return n != 0;
        int res = 0;
        for (int i = 3; i <= n; ++i) {
            res = a + b + c;
            a = b;
            b = c;
            c = res;
        }
        return res;
    }
};