class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& inter) {
    int n = inter.size();
    sort(inter.begin(), inter.end(), [](const auto& a, const auto& b){
      return (a[0] == b[0]) ? a[1] < b[1] : a[0] < b[0];
    });
    int res = 0;
    int i = 0;
    while (i < n) {
      int s = inter[i][0], e = inter[i][1];
      int del = 0;
      while (i + 1 < n && e > inter[i + 1][0]) {
        e = min(e, inter[i + 1][1]);
        ++i;
        ++del;
      }
      res += del;
      ++i; 
    }
    return res;
  }
};