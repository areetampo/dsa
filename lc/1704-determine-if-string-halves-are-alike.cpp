class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' ||
            s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            cnt += (i < n/2) ? 1 : -1;
        }
        return !cnt;
    }
};