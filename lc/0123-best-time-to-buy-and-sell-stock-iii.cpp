class Solution {
public:
    int maxProfit(vector<int>& v) {
      int n = v.size();
          //for section size 0, 1 -> only 0 profit possible
          vector<int> left(n + 1, 0);//left section max profit of all section sizes from 0 to n
          vector<int> right(n + 1, 0);//right ""
          int mn = v[0];
          //eg : section size at i is i + 1 (0 to i idxs)
          for (int i = 1; i < n; ++i) {
            //if v[i] - mn < 0 (v[i] is the min), overriden by stored 0 
            left[i + 1] = max(left[i], v[i] - mn);
            mn = min(mn, v[i]);
          }
          int mx = v[n-1];//now section taken from right which means traversing to left and keep track 
                          //of max sinc can only buy left el and sell right el
                          int idx = 2;//right[]'s idx : section size
          //eg : section size at i is i + 1 (0 to i idxs)
          for (int i = n-2; i >= 0; --i) {
              //if mx - v[i] < 0 (v[i] is the max), overriden by stored 0 
            right[idx] = max(right[idx - 1], mx - v[i]);
            mx = max(mx, v[i]);
            ++idx;
          }
          for (int& i : left) cout << i << " "; cout << endl;
          for (int& i : right) cout << i << " "; cout << endl;
          //now (left section 0 to i or left[i+1] + right section i + 1 to n-1 or right[n - i])'s max
          int res = 0;
          for (int i = 0; i <= n; ++i) res = max(res, left[i] + right[n - i]);
          return res;
    }
};