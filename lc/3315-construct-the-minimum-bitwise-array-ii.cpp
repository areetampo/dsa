class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& v) {
        vector<int> res;
        // any prime except 2 is an odd num
        // and to make it = k | k + 1 with k being minimum ->
        // find the leftmost set bit of the rightmost seq of 1s
        //(starts with 0th bit since num is odd) and set it to 0
        for (int &i : v) {
            if (i == 2) res.push_back(-1);
            else {
                int x = i, c = 0;
                while (x & 1) {
                    x >>= 1;
                    c++;
                }
                res.push_back(i & ~(1 << (c - 1)));
            }
        }
        return res;
    }
};
