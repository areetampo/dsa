/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */

 /*
 * ============================================================
 * APPROACH: line sweep over an ordered map of difference events
 * ============================================================
 *
 * k-booking = max number of events overlapping at any single time.
 *
 * Keep diff[t] = (# events starting at t) - (# events ending at t).
 * Walking the keys in sorted order and accumulating gives the number
 * of active events at each point, so max prefix sum = answer.
 *
 * Why not a plain array? Times go up to 1e9, too big to index directly.
 * Why not pre-compress? Queries arrive online, so we don't know the
 * endpoints ahead of time. An ordered map only stores the endpoints that
 * actually appear (at most 2 * 400 = 800), and iterates in sorted order.
 *
 * Half-open [start, end): an event ending at t and one starting at t share
 * the key t, so their +1 and -1 net out and they are not counted as
 * overlapping.
 *
 * Complexity per book: O(log m) insert + O(m) sweep, m <= 800.
 * Total: about 400 * 800 = 320k operations.
 * ============================================================
 */

class MyCalendarTwo {
  public:

  map<int, int> diff;  // time -> (+1 starts, -1 ends)

  MyCalendarTwo() {}

  bool book(int startTime, int endTime) {
    diff[startTime]++;
    diff[endTime]--;

    int cur = 0;
    for(auto& p: diff) {
      cur += p.second;
      if (cur > 2) {
        diff[startTime]--;
        diff[endTime]++;
        return 0;
      }
    }

    return 1;
  }
};

