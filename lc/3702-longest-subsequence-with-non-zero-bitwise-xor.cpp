class Solution {
public:
    int longestSubsequence(vector<int>& v) {
        int n = v.size();

        return all_of(v.begin(), v.end(), [&](int a) {
                    return a == 0;
                }) ? 0 : 
                accumulate(v.begin(), v.end(), 0, bit_xor<int>()) == 0 ? n - 1 : n;
    }
};