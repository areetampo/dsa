class Solution {
public:
    bool rotateString(string s, string g) {
        if (s.size() != g.size()) return 0;
        for (int rotation = 0; rotation < s.size(); rotation++) {
            int i = 0;
            for (; i < s.size(); i++) {
                if (s[i] != g[(i + rotation) % s.size()]) break;
            }
            if (i == s.size()) return 1;
        }
        return 0;
    }
};