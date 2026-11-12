class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0, h = sqrt(c), m = -1;
        while (l <= h) {
            if (l * l + h * h == c) return 1;
            else if (l * l + h * h < c) l++;
            else h--;
        }
        return 0;

    }
};