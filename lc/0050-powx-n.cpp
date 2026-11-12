class Solution {
public:
    double myPow(double x, int n) {
        unsigned int N = abs(n);
        double ans = 1;
        while (N) {
            if (N & 1) {
                ans *= (n > 0) ? x : 1/x;
            }
            x *= x;
            N >>= 1;
        }
        return ans;
    }
};