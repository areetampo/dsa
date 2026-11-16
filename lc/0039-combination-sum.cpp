class Solution {
public:
  vector<vector<int>> res;
  void dfs(int i, int x, vector<int>& v, vector<int>& t) {
    if (x == 0) res.push_back(t);
    if (x <= 0 || i == v.size()) return;
    dfs(i + 1, x, v, t);//exclude el
    //include and go to same idx: will have include that again/move to next idx cases
    t.push_back(v[i]);
    dfs(i, x - v[i], v, t);
    t.pop_back();
  }
  vector<vector<int>> combinationSum(vector<int>& v, int x) {
    res.clear();
    vector<int> t;//temp
    dfs(0, x, v, t);
    return res;
  }
};