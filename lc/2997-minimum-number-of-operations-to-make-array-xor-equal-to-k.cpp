class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorr = 0;
        for (int i : nums) xorr ^= i;
        //for xorr == k -> xorr ^ k == 0
        xorr ^= k;
        //flip the set bits present
        int res = 0;
        while (xorr) {
            xorr &= xorr - 1;
            ++res;
        }
        return res;
    }
};