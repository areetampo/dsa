class Solution {
public:
    int isPrefixOfWord(string s, string w) {
        for (int i = 0, res = 1; i < s.size(); res++, i++) {
            if (s.substr(i, w.size()) == w) return res;
            while (i < s.size() && s[i] != ' ') i++;
        }
        return -1;
    }
};