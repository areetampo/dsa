class Solution {
public:
    int res;
void permutations(int i, vector<int>& v, int k) {
  if (i == v.size()) {
    int r = 0, x = 1;
    for (int& i : v) {
        r += ceil((double)i / x);
          x += k;
    }
    res = min(res, r);
  }
  for (int j = i; j < v.size(); j++) {
    swap(v[i], v[j]);
    permutations(i + 1, v, k);
    swap(v[i], v[j]);
  }
}
int findMinimumTime(vector<int>& v, int k) {
  res = INT_MAX;
  permutations(0, v, k);
  return res;
}
};