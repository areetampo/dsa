class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) return 0;
            n /= 3;//handles for n or n + 1 is divisible by 3
        }
        return 1;
    }
};