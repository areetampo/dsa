class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& e, int src, int dst, int k) {
    vector<vector<int>> adj(n, vector<int>(n, 0));//price > 0 so no edge if price = 0
    for (auto& i : e) adj[i[0]][i[1]] = i[2];
    vector<int> dist(n, INT_MAX); dist[src] = 0;
    //<<node totalDist> stops> sort by stops then by distance 
    //if not using stops then lesser distances appear earlier who not within k stops 
    //so can't really break the while loop as uncertainity
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, decltype([]
      (const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b){
        return b.first.second > a.first.second;
    })> pq;
    pq.push({{src, 0}, 0});
    while (!pq.empty()) {
      int v = pq.top().first.first, totalDist = pq.top().first.second, stops = pq.top().second; 
      pq.pop();
      cout << endl << "node: " << v << ", dist here: " << totalDist << ", stops: " << stops << " | ";
      if (stops <= k)//max stop until now : k so next node is k + 1 th node from src
      for (int neighbor = 0; neighbor < n; ++neighbor) {
        if (adj[v][neighbor]) {//if edge exists (!= 0)
          if (dist[neighbor] > totalDist + adj[v][neighbor]) {
            dist[neighbor] = totalDist + adj[v][neighbor];
            pq.push({{neighbor, dist[neighbor]}, stops + 1});
            cout << neighbor << " ";
          }
        }
      }
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
  }
};