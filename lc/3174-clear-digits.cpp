class Solution {
public:
    string clearDigits(string s) {
        int r = 0, w = 0;
        while (r < s.size()) {
            if (w > 1 && s[w - 1] < 'a' && s[w - 2] >= 'a') w -= 2;
            s[w++] = s[r++];
        }
        if (w > 1 && s[w - 1] < 'a' && s[w - 2] >= 'a') w -= 2;
        s.resize(w);
        return s;
    }
};