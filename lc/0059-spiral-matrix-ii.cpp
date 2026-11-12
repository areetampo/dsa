class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};
        int currIdx = 0, i = 0, j = 0;
        for (int x = 1; x <= n * n; x++) {
            // cout << i << " " << j << endl;
            res[i][j] = x;
            int ni = i + di[currIdx], nj = j + dj[currIdx];
            if (min(ni, nj) < 0 || ni == n || nj == n || res[ni][nj] != 0) currIdx = (currIdx + 1) % 4;
            i += di[currIdx], j += dj[currIdx];
        }
        return res;
    }
};