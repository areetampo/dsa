class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xorNums = 0, xorN = 0;
        for (int &i : nums) xorNums ^= i;
        for (int i = 1; i <= n; ++i) xorN ^= i;
        int x = xorN ^ xorNums;//x = xor of missing and duplicate
        int lsb = 1;//to represent the lsb in x
        while ((x & lsb) == 0) {
            lsb <<= 1;
        }
        //filter out from nums with that lsb and nums not with that lsb
        //eg: 1 2 2 4 === 1 10 10 100, real: 1 10 11 100 [1, 2, 3, 4]
        //x = 2 ^ 3 = 1, lsb = 1
        //from nums: with lsb -> 1 1 3, without -> 2 2 2 4 4
        //x ^ with lsb = 2 = duplicate, x ^ without lsb = 3 = missing
        int a = x, b = x;
        for (int &i : nums) {
            if (i & lsb) a ^= i;
            else b ^= i;
        }
        for (int i = 1; i <= n; ++i) {
            if (i & lsb) a ^= i;
            else b ^= i;
        }
        //now a has to be duplicate and b reapeating
        bool t = false;
        for (int &i : nums) if (i == a) {t = 1; break;}
        if (t) return {a, b};
        return {b, a};
    }
};