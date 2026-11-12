class Solution {
public:
    vector<int> getFinalState(vector<int>& v, int k, int m) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < v.size(); i++) pq.push({v[i], i});
        while (k--) {
            auto [el, idx] = pq.top(); pq.pop();
            v[idx] *= m;
            pq.push({el * m, idx});
        }
        return v;
    }
};