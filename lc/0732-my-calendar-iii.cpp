class MyCalendarThree {
  public:

  map<int, int> diff; // line sweep

  MyCalendarThree() {}

  int book(int startTime, int endTime) {
    diff[startTime]++;
    diff[endTime]--;

    int cur = 0, mx = 0;
    for(auto& p: diff) {
      cur += p.second;
      mx = max(mx, cur);
    }
    
    return mx;
  }
};