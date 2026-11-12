class Solution {
public:
    string makeFancyString(string s) {
        int w = 3;
        for (int r = 3; r < s.size(); r++) {
            if (s[w - 1] == s[w - 2] && s[w - 2] == s[w - 3]) 
                w--;
            s[w++] = s[r];
        }
        if (s.size() >= 3 && s[w - 1] == s[w - 2] && s[w - 2] == s[w - 3]) 
            w--;
        return s.substr(0, w);
    }
};