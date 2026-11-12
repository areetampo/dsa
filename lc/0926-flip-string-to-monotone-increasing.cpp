class Solution {
public:
    int minFlipsMonoIncr(string s) {//same as 1653, see it for explanation
        int ones = s[0] == '1', res = 0;
        for (int i = 1; i < s.length(); i++) {
            char c = s[i];
            if (c == '0') {
                res = min(res + 1, ones);
            } else ones++;
            // dbg(res);
        }
        return res;
    }
};