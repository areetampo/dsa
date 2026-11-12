class Solution {
public:
    int appendCharacters(string s, string t) {
        int j = 0;
        for (char &c : s) {
            if (c == t[j] && ++j == t.length()) break;
        }
        return t.length() - j;
    }
};