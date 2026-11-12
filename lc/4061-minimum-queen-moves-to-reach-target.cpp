class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int sx = source[0], sy = source[1], tx = target[0], ty = target[1],
          dx = abs(sx - tx), dy = abs(sy - ty);

        return sx == tx && sy == ty ? 0 : min(dx, dy) == 0 && max(dx, dy) > 0 || dx == dy ? 1 : 2; 
    }
};