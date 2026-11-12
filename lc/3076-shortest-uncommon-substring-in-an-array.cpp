class Solution {
public://brute force
    vector<string> shortestSubstrings(vector<string>& a) {
      int n = a.size();
      vector<unordered_map<string, int>> v(21);//global map for all substrings
      for (int i = 0; i < n; i++) {
        int m = a[i].size();
        for (int j = 0; j < m; j++) {
          string s = "";
          for (int k = j; k < m; k++) {
            s += a[i][k];
            v[s.size()][s]++;
          }
        }
      }
      // for (int i = 0; i < 21; i++) {
      //   for (auto it = v[i].begin(); it != v[i].end(); it++) {
      //     cout << it->first << " " << it->second << endl;
      //   }
      // }
      vector<string> res(n, "");
      for (int i = 0; i < n; i++) {//for each substring of arr
        int sz = a[i].size();
        for (int len = 1; len <= sz; len++) {// for its substring(s) of length = len
          unordered_map<string, int> mp;
          for (int start = 0; start < sz; start++) {
            if (start + len - 1 >= sz) break;
            mp[a[i].substr(start, len)]++;
          }
          for (auto it = mp.begin(); it != mp.end(); it++) {
            //now for a specific len substr len goes 0 to sz 
            //if that substring only part of this str then include otherwise
            //if part of other substr as well then total freq will be (>)
            if (v[len][it->first] == it->second) {
              res[i] == "" ? res[i] = it->first : res[i] = res[i].compare(it->first) < 0 ? res[i] : it->first;
            }
          }
          if (res[i] != "") break;//min len (len goes 0 to sz) substr of str (a[i]) found
        }
      }
      return res;
    }
};