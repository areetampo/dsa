class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& g) {
        vector<int> res; int n = g.size(), m = g[0].size();
        for (int i = 0; i < n; i++) {
            int j = i % 2 == 0 ? 0 : m - 1;
            if (i % 2 == 1 && m % 2 == 1) j--;
            // cout << j << " ";
            while (j >= 0 && j < m) {
                res.push_back(g[i][j]);
                if (i % 2 == 0) j += 2;
                else j -= 2;
            }
        }
        return res;
    }
};