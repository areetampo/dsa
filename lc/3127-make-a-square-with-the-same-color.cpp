class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& g) {
        for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) if (g[i][j] == 'W') g[i][j] = 1;
        else g[i][j] = 0;
    }
    int a = g[0][0] + g[0][1] + g[1][0] + g[1][1];
    int b = g[0][1] + g[0][2] + g[1][1] + g[1][2];
    int c = g[1][0] + g[1][1] + g[2][0] + g[2][1];
    int d = g[1][1] + g[1][2] + g[2][1] + g[2][2];
    if (a >= 3 || a <= 1) return 1;
    if (b >= 3 || b <= 1) return 1;
    if (c >= 3 || c <= 1) return 1;
    if (d >= 3 || d <= 1) return 1;
    return 0;
    }
};