class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& p) {
    int n = p.size();
    sort(p.begin(), p.end(), [](const auto& a, const auto& b){
      return (a[0] == b[0]) ? a[1] < b[1] : a[0] < b[0];
    });
    int res = 0;
    int i = 0;
    while (i < n) {
      int s = p[i][0], e = p[i][1];
      while (i + 1 < n && e >= p[i + 1][0]) {
        s = max(s, p[i + 1][0]);
        e = min(e, p[i + 1][1]);
        ++i;
      }
      ++res;
      ++i;
    }
    return res;
  }
};