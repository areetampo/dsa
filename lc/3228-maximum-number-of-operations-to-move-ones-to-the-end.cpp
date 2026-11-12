class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
    int res = 0;
    int i = n - 1, zg = 0;//zero groups
    while (i >= 0) {
        int z = 0;
        while (i >= 0 && s[i] == '0') {
            i--;
            z++;
        }
        if (z) zg++;
        int ones = 0;
        while (i >= 0 && s[i] == '1') {
            i--;
            ones++;
        }
        res += ones * zg;
    }
    return res;
    }
};