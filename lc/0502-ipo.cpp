class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        int n = p.size();
        vector<pair<int, int>> v;//capital, profit
        for (int i = 0; i < n; i++) v.push_back({c[i], p[i]});
        sort(v.begin(), v.end());
        priority_queue<int> pq;//track max profit
        for (int i = 0; i < n; ) {
            while (i < n && v[i].first <= w) {
                pq.push(v[i].second);
                i++;
            }
            if (pq.size()) {
                w += pq.top(); pq.pop();
                if (--k == 0) break;
            } else break;//0 capitals <= w and v sorted so next idxs also 0 capitals <= w and pq remains empty only
        }
        while (k-- && pq.size()) {//leftover profitable projects (<= k)
            w += pq.top(); pq.pop();
        }
        return w;
    }
};