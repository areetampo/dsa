typedef pair<int, int> pi;
class Solution {
public:
    int minOperations(int n, int m) {
      vector<bool> isPrime(1e4 + 1, true);
      isPrime[0] = isPrime[1] = false;
      for (int p = 2; p * p <= isPrime.size(); ++p) {
        if (isPrime[p]) {
          for (int i = p * p; i <= isPrime.size(); i += p) {
            isPrime[i] = false;
          }
        }
      }
        if (isPrime[n] || isPrime[m]) return -1;
      vector<bool> vis(1e4 + 1, false);
      priority_queue<pi, vector<pi>, greater<pi>> pq;//min heap cost, number
      pq.push({ n, n });
      while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int cost = p.first, num = p.second;
        if (num == m) return cost;
        if (vis[num]) continue;
        vis[num] = true;
        for (int i = 10, j = 0; j <= log10(num); j++, i *= 10) {
          int change_digit = (num % i) / (i / 10);
          if (change_digit > 0) {
            int newNum = num - i / 10;
            if (!isPrime[newNum] && !vis[newNum]) pq.push({ cost + newNum, newNum });
          }
          if (change_digit < 9) {
            int newNum = num + i / 10;
            if (!isPrime[newNum] && !vis[newNum]) pq.push({ cost + newNum, newNum });
          }
        }
      }
      return -1;
    }
};