class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r, int c) {
        vector<vector<int>> res = { {r,c} };
    int dx = 1, dy = 0;
    for (int n = 1; res.size() != R * C; n++) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                r += dy, c += dx;
                // dbg(n); dbg(dx); dbg(dy); dbg(r); dbg(c); dbg(res.size()); small_line();
                if (0 <= r && r < R && 0 <= c && c < C)
                    res.push_back({ r, c });
            }
            if (dx == 0) {
                if (dy == 1) {//going down
                    dx = -1;//to left
                } else dx = 1;//going up to right
                dy = 0;
            } else if (dy == 0) {
                if (dx == 1) {//going right
                    dy = 1;//to down
                } else dy = -1;//going left to up
                dx = 0;
            }
        }
    }
    // dbg(res);
    return res;
    }
};