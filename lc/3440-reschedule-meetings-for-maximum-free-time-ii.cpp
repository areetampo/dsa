class Solution {
public:
    int maxFreeTime(int total_time, vector<int>& start, vector<int>& end) {
  int n = start.size();
  vector<int> left_max_gap = { start[0] },
    right_max_gap = { total_time - end[n - 1] };
  for (int i = 1; i < n; i++)
    left_max_gap.push_back(max(left_max_gap.back(), start[i] - end[i - 1]));
  for (int i = n - 2; i >= 0; i--)
    right_max_gap.push_back(max(right_max_gap.back(), start[i + 1] - end[i]));
  reverse(right_max_gap.begin(), right_max_gap.end());
  if (n == 1) return total_time - (end[0] - start[0]);
  if (n == 2) {
    int r = max(start[0] + start[1] - end[0], total_time - end[1] + start[1] - end[0]);
    if (total_time - end[1] >= end[0] - start[0])
      r = max(r, start[1]);
    if (start[0] >= end[1] - start[1])
      r = max(r, total_time - end[0]);
    return r;
  }
  int res = 0, lo = 0, hi = 1e9;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    bool possible = 0;
    for (int i = 2; i < n; i++) {
      int middle_time = end[i - 1] - start[i - 1];
      if ((start[i] - end[i - 2] >= mid &&
        (middle_time <= left_max_gap[i - 2] || middle_time <= right_max_gap[i])) ||
        start[i - 1] - end[i - 2] + start[i] - end[i - 1] >= mid) {
        possible = 1;
        break;
      }
    }
    if (possible) {
      res = mid;
      lo = mid + 1;
    } else hi = mid - 1;
  }
  int r = max(start[0] + start[1] - end[0],
    total_time - end[n - 1] + start[n - 1] - end[n - 2]);
  for (int i = 1; i < n; i++)
    r = max(r, start[i] - end[i - 1]);
  if (right_max_gap[1] >= end[0] - start[0])
    r = max(r, start[1]);
  if (left_max_gap[n - 2] >= end[n - 1] - start[n - 1])
    r = max(r, total_time - end[n - 2]);
  // dbg(r, res);
  return max(r, res);
}
};