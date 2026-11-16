class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> v(52, 0);
        for (char &c : s) {
            v[c - (c >= 97 ? 97 : 65 - 26)]++;
        }
        int even = 0, o = -1;
        for (int i = 0; i < 52; i++) {
            if (v[i] % 2) {
                if (o == -1) o = i;
                else o = v[i] > v[o] ? i : o;
            }
            else even += v[i];
        }
        for (int i = 0; i < 52; i++) if (v[i] % 2 && i != o) even += v[i] - 1; 
        return o == -1 ? even : v[o] + even;
    }
};