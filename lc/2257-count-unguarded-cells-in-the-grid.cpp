class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<int>> v(n, vector<int>(m, -2));
        //1 walls
        for (auto W : w) v[W[0]][W[1]] = 1;
        //-1 gaurds
        for (auto G : g) v[G[0]][G[1]] = -1;
        //for each gaurd mark it 0 and traverse its edges (that are -2) 
        //marking them 0 until boundary or another gaurd (-1) or wall (1) hits
        //basically marking until only -2s appear cuz wall is blockage and another
        //gaurd means that gaurd will continue to see beyond that row/col further
        //now to avoid TLE: when going up check if a gaurd has alr marked 0s going 
        //down and when going left check if a gaurd has alr marked 0s going right
        //since the right and down cells will be non 0 since grid is traversed
        //up to down and left to right
        //5 for up/down and 6 for left/right
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
            if (v[i][j] == -1) {//gaurd present
                v[i][j] = 5;//or 6
                int x = i, y = j;
                //go up and left until hits a wall or another gaurd looking down/left
                while (--x >= 0 && v[x][j] != 1 && v[x][j] != 5) v[x][j] = 5;//up
                while (--y >= 0 && v[i][y] != 1 && v[i][y] != 6) v[i][y] = 6;//left
                x = i, y = j;
                //go down and right until hits a wall or gaurd
                while (++x < n && abs(v[x][j]) != 1) v[x][j] = 5;//down
                while (++y < m && abs(v[i][y]) != 1) v[i][y] = 6;//right
            }
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << v[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        //in end count -2 cells
        int target = -2;
        return accumulate(v.begin(), v.end(), 0, 
            [target](int sum, const vector<int>& row) {
                return sum + count(row.begin(), row.end(), target);
            }
        );
    }
};