class Solution {
public:
  vector<int> asteroidCollision(vector<int>& v) {//collision only when left > 0, right < 0
    vector<int> res;
    stack<int> s;
    int i = 0;
    while (i < v.size()) {
      int x = 0;
      while (s.size() && s.top() > 0 && v[i] < 0) {
        if (abs(s.top()) == abs(v[i])) { x = 1; s.pop(); break; }
        else if (abs(s.top()) > abs(v[i])) { x = 1; break; }
        else s.pop();
      }
      if (!x) s.push(v[i]);
      ++i;
    }     
    while (!s.empty()) { res.push_back(s.top()); s.pop(); }
    reverse(res.begin(), res.end());
    return res;
  }
};