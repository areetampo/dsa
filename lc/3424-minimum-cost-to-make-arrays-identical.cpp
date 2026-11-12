class Solution {
public:
    long long minCost(vector<int>& a, vector<int>& b, long long k) {
        int n = a.size();
  vector<pair<int, int>> aa, bb;
  for (int i = 0; i < n; i++) {
    aa.push_back({a[i], i});
    bb.push_back({b[i], i});
  }
  sort(aa.begin(), aa.end()); sort(bb.begin(), bb.end());
  long long res = 0, r = 0; bool add_k = 0;
  for (int i = 0; i < n; i++) {
    res += abs(aa[i].first - bb[i].first);
    if (aa[i].second != bb[i].second) add_k = 1;
    r += abs(a[i] - b[i]);
  }
  return min(res + add_k * k, r);
    }
};