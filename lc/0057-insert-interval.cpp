class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newInter) {
    int x = newInter[0], y = newInter[1];
    vector<vector<int>> res;
    int i = 0;
    while (i < inter.size() && inter[i][1] < x) {
      res.push_back(inter[i]);
      ++i;
    }
    if (i == inter.size()) {
      res.push_back(newInter);
      return res;
    }

    int start = min(x, inter[i][0]);
    int end = y;
    while (i < inter.size() && end >= inter[i][0]) {
      end = max(end, inter[i][1]);
      ++i;
    }
    res.push_back({start, end});

    while (i++ < inter.size()) {
      res.push_back(inter[i - 1]);
    }
    return res;
  }
};