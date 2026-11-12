class Solution {
public:
    vector<int> singleNumber(vector<int>& v) {
        int xorr = 0;
        for (int i : v) xorr ^= i;
        int lsb = xorr == INT_MIN ? xorr : (xorr & (xorr - 1)) ^ xorr;
        int a = xorr, b = xorr;
        for (int i : v) {
            if (i & lsb) a ^= i;
            else b ^= i;
        }
        return {a, b};
    }
};