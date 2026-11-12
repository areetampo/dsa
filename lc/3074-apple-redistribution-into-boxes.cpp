class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int s = 0;
      for (int & i : apple) s += i;
      sort(capacity.rbegin(), capacity.rend());
      int i = 0;
      while (i < capacity.size()) {
        if (s <= 0) break;
        s -= capacity[i++];
      }
      return i;
    }
};