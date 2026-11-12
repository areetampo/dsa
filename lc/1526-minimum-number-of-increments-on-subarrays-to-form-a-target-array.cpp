class Solution {
public:
    int minNumberOperations(vector<int>& a) {
      int n = a.size();
      long long res = 0, prev = 0;

      for (int i = 0; i < n; i++) {
        if (a[i] > prev) res += a[i] - prev;
        prev = a[i];
      }

      // a[n-1] = prev, a[n] = 0
      if (prev < 0) res += prev;
      return res;
    }
};
