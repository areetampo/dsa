class Solution {
public:
    string losingPlayer(int x, int y) {
        y /= 4;
        int k = min(x, y);
        return k % 2 ? "Alice" : "Bob";
    }
};