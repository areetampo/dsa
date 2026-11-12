class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& g) {
        if (g[0][0] != 0) // this is silly ;p
            return false;
        array<int, 2> m[7 * 7] = {};
        for (int x = 0; x < g.size(); ++x)
            for (int y = 0; y < g.size(); ++y)
                m[g[x][y]] = {x, y};
        for (int i = 1; i < g.size() * g.size(); ++i)
            if (abs((m[i][0] - m[i - 1][0]) * (m[i][1] - m[i - 1][1])) != 2)
                return false;
        return true;
    }
};