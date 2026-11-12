class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<int> res;
    for (int x = 0; x < n + m; ++x) {
      int i = x;
      int j = 0;
      if (i >= n) {
        i = n - 1;
        j = x - i;
      }
      vector<int> segment;
      while (i >= 0 && j < m) {
        segment.push_back(mat[i--][j++]);
      }
      if (x % 2) {
        for (int k = segment.size() - 1; k >= 0; --k) res.push_back(segment[k]);
      } else {
        for (int &k : segment) res.push_back(k);
      }
    }
    return res;
  }
};