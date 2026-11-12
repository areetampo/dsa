class Solution {
public:
    int minimumRecolors(string s, int k) {
        //min W -> B so k consecutive B's
        int res = 0;
        for (int i = 0; i < k; i++) res += s[i] == 'W';
        for (int i = k, curr = res; i < s.size(); i++) {
            res = min(res, curr += - (s[i - k] == 'W') + (s[i] == 'W'));
        }
        return res;
    }
};