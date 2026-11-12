class Solution {
public:
    int maxDistance(string s) {
        int x = 0, y = 0, d = 0;
        for (char& c : s) {
            x += c == 'R';
            x -= c == 'L';
            y += c == 'U';
            y -= c == 'D';
            d += c == '_';
        }
        return abs(x) + abs(y) + d;
    }
};