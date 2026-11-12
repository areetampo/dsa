class Solution {
public:
  int minMoves(vector<int>& a) {
    return a.size() * *max_element(a.begin(), a.end()) - accumulate(a.begin(), a.end(), 0);
  }
};