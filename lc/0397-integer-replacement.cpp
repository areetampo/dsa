class Solution {
  public:
  int integerReplacement(int N) {
    long long n = N;
    int res = 0;

    while (n > 1) {
      if (!(n & 1)) n >>= 1;
      else  if (n == 3 || !((n >> 1) & 1)) n--;
      else n++;

      res++;
    }

    return res;
  }
};
