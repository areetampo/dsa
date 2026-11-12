class Solution {
public:
    long long maxSum(vector<vector<int>>& g, vector<int>& l, int k) {
        for (auto &i : g) sort(i.rbegin(), i.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < l[i]; j++) {
                pq.push(g[i][j]);
                if (pq.size() > k) pq.pop();
            }
        }
        long long res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};