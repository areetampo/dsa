class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int X = x;
        int Y = 0;
        while (x) {
            Y += x % 10;
            x /= 10;
        }
        return X % Y == 0 ? Y : -1;
    }
};