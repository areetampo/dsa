class Solution {
public:
    bool isCircularSentence(string s) {
        for (int i = 0; i < s.size(); i += 2) {
            while (i + 1 < s.size() && s[i + 1] != ' ') i++;
            if (i + 2 < s.size() && s[i] != s[i + 2]) return 0;
        }
        return s[0] == s[s.size() - 1];
    }
};