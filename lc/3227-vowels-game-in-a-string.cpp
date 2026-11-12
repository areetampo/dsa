class Solution {
public:
    bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
bool doesAliceWin(string s) {
    int n = s.length(), v = 0, f = -1, l = -1;
    for (int i = 0; i < n; i++) {
        if (isVowel(s[i])) {
            v++;
            if (f == -1) f = i;
            l = i;
        }
    }
    if (v == 0) return 0;
    if (v % 2) return 1;
    //v >= 2 and even
    // if (f != 0 && l != n - 1) return 1;
    // if (f != 0 && l != n - 1) return 1;
    return 1;
}
};