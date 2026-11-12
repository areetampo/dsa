class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        int f[3] = {2,3,5};
        for (auto& x : f) {
            while (n % x == 0) n /= x;
        }
        return n == 1;
    }
};