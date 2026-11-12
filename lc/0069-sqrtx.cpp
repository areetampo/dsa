class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, h = x, m = -1;
        while (l <= h) {
            m = l + (h-l)/2;
            if (m*m == x) return m;
            if (m*m < x) l = m + 1;
            else h = m - 1;
        }
        return h;
    }
};