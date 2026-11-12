class Solution {
public:
    int pivotInteger(int n) {
        // x * (x + 1) / 2 = n * (n + 1) / 2 - x * (x + 1) / 2 + x
        // x * x = n * (n + 1) / 2;
        int res = sqrt (n * (n + 1) / 2);
        return res * res == n * (n + 1) / 2 ? res : -1;
    }
};