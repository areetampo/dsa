class Solution {
public://can do simply as well by directly using substrings instead of pointers
//regards to follow up, using string additions and carry variable so no overflow
  int f(int as, int ae, int bs, int be, string& s) {
    // cout << "in" << endl;
    //no res substring possible or leading 0s with len > 1 (if len = 1 means only one 0)
    if (be == s.length() - 1 || s[as] == '0' && ae > as || s[bs] == '0' && be > bs) return -1;
    string res = "";
    int carry = 0;
    int end = be;
    while (be >= bs && ae >= as) {
      char a = s[ae], b = s[be];
      char c = (((int)(a - '0') + (int)(b - '0') + carry) % 10) + '0';
      carry = ((int)(a - '0') + (int)(b - '0') + carry) / 10;
      --ae; --be;
      res += c;
    }
    // cout << res << " " << carry << endl;
    while (be >= bs) {
      char b = s[be];
      char c = (((int)(b - '0') + carry) % 10) + '0';
      carry = ((int)(b - '0') + carry) / 10;
      --be;
      res += c;
    }
    // cout << res << " " << carry << endl;
    while (ae >= as) {
      char a = s[ae];
      char c = (((int)(a - '0') + carry) % 10) + '0';
      carry = ((int)(a - '0') + carry) / 10;
      --ae;
      res += c;
    }
    if (carry) res += (char)(carry + '0');
    int idx = end + 1;
    // cout << res << " " << carry << endl;
    // cout << "out" << endl;
    int i = res.length() - 1;
    while (i >= 0 && idx <= s.length()) {
      if (s[idx++] != res[i--]) return -1;
    }
    return i == -1 ? idx - 1 : -1;//complete sum found ? (or few digits only until idx end)
  }
  bool isAdditiveNumber(string s) {
    int n = s.length();
    for (int i = 0; i < n; ++i) {//tracking possible left
      for (int j = i + 1; j < n; ++j) {//tracking possible right
        int as = 0, ae = i, bs = i + 1, be = j;//start and end of num a and b
        while (1) {//until i + until j sum found: shift both to next numbers and find new sum
          // cout << s.substr(as, ae - as + 1) << " " << s.substr(bs, be - bs + 1)  << endl; 
          int resEnd = f(as, ae, bs, be, s);
          if (resEnd == -1) break;
          if (resEnd == n - 1) return 1;
          as = bs; ae = be;
          bs = be + 1; be = resEnd;
        }
      }
    }    
    return 0; 
  }
};