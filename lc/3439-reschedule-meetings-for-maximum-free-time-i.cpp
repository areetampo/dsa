class Solution {
public:
int maxFreeTime(int total_time, int k, vector<int>& start, vector<int>& end) {
  vector<int> v;
  if (start[0] > 0) {
    v.push_back(start[0]);
  }
  for (int i = 1; i < start.size(); i++) {
    v.push_back(start[i] - end[i - 1]);
  }
  if (end.back() < total_time) {
    v.push_back(total_time - end.back());
  }
  k = min(k + 1, (int)v.size());
  //maximum window sum of size k
  int n = v.size();
  int sum = 0;
  for (int i = 0; i < k; i++) {
    sum += v[i];
  }
  int max_sum = sum;
  for (int i = k; i < n; i++) {
    sum += v[i] - v[i - k];
    max_sum = max(max_sum, sum);
  }
  return max_sum;
}
};