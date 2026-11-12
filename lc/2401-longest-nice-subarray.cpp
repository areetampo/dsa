class Solution {
public:
    int longestNiceSubarray(vector<int>& a) {
        //a, b, c, d has all pairs & = 0
        //so that means all numbers have different set bits
        int r = 0;
        for (int i = 0, j = 0, unique = 0; j < a.size(); j++) {
            while ((unique & a[j]) > 0) unique ^= a[i++];
            unique |= a[j];
            r = max(r, j - i + 1); 
        }
        return r;
    }
};