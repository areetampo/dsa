class Solution {
public:
    int minBishopMoves(vector<int>& s, vector<int>& t) {
        int dx = abs(t[0] - s[0]), dy = abs(t[1] - s[1]);

        if (dx % 2 != dy % 2) return -1;
        if (dx == dy) return 1;
        return 2;
    }
};