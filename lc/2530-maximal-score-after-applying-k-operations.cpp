class Solution {
public:
    long long maxKelements(vector<int>& v, int k) {
        priority_queue<int> pq(v.begin(), v.end());
        long long res = 0;
        for (int i = 0; i < k && pq.size(); i++) {
            res += pq.top(); pq.push((pq.top() + 2) / 3);
            pq.pop();
        }
        return res;
    }
};