class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        int X = abs(x);
        long long ans = 0;
        while (X) {
            ans = (ans * 10) + (X % 10);
            X /= 10;
        }
        if (x < 0) ans = -ans;
        if (x > 0 && ans > INT_MAX || x < 0 && ans < INT_MIN) return 0;
        return ans;
    }
};