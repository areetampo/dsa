class Solution {
public:
  vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    // list cuz max nodes = max edges when 1e5
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>(0)); // dst, meetingTime
    for (auto& e : meetings) {
      adj[e[0]].push_back({e[1], e[2]});
      adj[e[1]].push_back({e[0], e[2]});
    }
    //<node, meetingTime>
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype([](const auto& a, const auto& b) {
      return a.second > b.second;
    })> pq;
    pq.push({0, 0});
    pq.push({firstPerson, 0});
    vector<int> vis(n, 0); // mark vis when pq.pop() cuz:
    // suppose node x gets to know secret before then again gets know, but
    // alr added to pq previously with low meet time so will spread to all
    // neighbors when first encountered in pq (mark vis here on pop())
    while (!pq.empty()) {
      //time until now is the time passed until curr node is encountered
      int v = pq.top().first, timeUntilNow = pq.top().second; pq.pop();
      // cout << endl << v << " " << timeUntilNow << " | ";
      // if (vis[v]) cout << "vis alr";
      if (!vis[v]) {
        vis[v] = 1;
        for (auto& i : adj[v]) {
          int neighbor = i.first, nextTime = i.second;
          if (timeUntilNow <= nextTime) {//the next time cannot be less otherwise no meeting possible
            // cout << neighbor << " " << nextTime << ", ";
            pq.push({neighbor, nextTime});
          }
        }
      }
    }
    vector<int> res;
    for (int i = 0; i < n; ++i) if (vis[i]) res.push_back(i);
    return res;
  }
};