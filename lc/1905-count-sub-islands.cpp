class Solution {
public:
int dfs(vector<vector<int>>& g1, vector<vector<int>>& g2, int i, int j) {
    int res = 1, n = g1.size(), m = g1[0].size();
    if (i < 0 || i == n || j < 0 || j == m || !g2[i][j]) return 1;
    //current [i][j] cell we are standing at will always be 1 so if adj cell is 0 then current cell is a guaranteed sub island as long as that cell value is 1 in g1 as well
    //note g1: [1,0,0], g2: [1,1,0] since the second island cell in g2 is not in g1, res = 0
    g2[i][j] = 0;//marking cell as vis
    res &= dfs(g1, g2, i + 1, j);
    res &= dfs(g1, g2, i - 1, j);
    res &= dfs(g1, g2, i, j + 1);
    res &= dfs(g1, g2, i, j - 1);
    //now res is 1 if the adj cells forms an island and in the end stepped out of bounds or on a 0 and returned 1
    return res & g1[i][j];//that returned value at all those g2 island cells was matched with g1's cell using & operation so if any cell is 0 then res will be 0 and will return 0 to main in the end
}
int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
    int res = 0, n = g1.size(), m = g1[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g2[i][j]) {
                res += dfs(g1, g2, i, j);
            }
        }
    }
    return res;
}
};