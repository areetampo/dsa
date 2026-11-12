class Solution {
public:
  int diffAtMostK(vector<int>& v, int k) {
    int res = 0;//total subarrays
    int i = 0, j = -1;
    unordered_map<int, int> mp;//val, freq
    while (++j < v.size()) {
      ++mp[v[j]];
      while (i <= j && mp.size() > k) {
        if (!--mp[v[i++]]) mp.erase(v[i - 1]);
      }
      if (mp.size() <= k)  res += j - i + 1;
    }
    return res;
  }
  int subarraysWithKDistinct(vector<int>& v, int k) {
    return diffAtMostK(v, k) - diffAtMostK(v, k - 1);
  }
};