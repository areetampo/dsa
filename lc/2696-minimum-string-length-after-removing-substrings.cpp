class Solution {
public:
    int minLength(string s) {
        int w = 0;
        for (int r = 0; r < s.length(); r++) {
            s[w++] = s[r];
            if (w >= 2 && (s[w - 2] == 65 && s[w - 1] == 66 || s[w - 2] == 67 && s[w - 1] == 68)) {
                w -= 2;
            }
        }
        return w;
    }
};