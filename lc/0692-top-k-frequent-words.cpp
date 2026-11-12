class Solution {//m2 - bucket sort but worst case nlogn
public:
    struct strFreq {
        string s;
        int cnt;
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (string &s : words) ++m[s];
        priority_queue<strFreq, vector<strFreq>, decltype([](const strFreq& a, const strFreq& b){
            // return (a.cnt == b.cnt) ? b.s > a.s : a.cnt > b.cnt;
            return (a.cnt == b.cnt) ? a.s < b.s : a.cnt > b.cnt;
        })> pq;//         puts first: bigger str  lower freq first
        //same in q 347
        for (auto it = m.begin(); it != m.end(); ++it) {
            pq.push({it->first, it->second});
            if (pq.size() > k) pq.pop();
        }
        // {//just printing the pq
        //     queue<strFreq> q;
        //     while (!pq.empty()) {
        //         cout << pq.top().s << " " << pq.top().cnt << endl;
        //         q.push(pq.top()); pq.pop();
        //     }
        //     while (!q.empty()) { pq.push(q.front()); q.pop(); }
        // }
        // while (pq.size() > k) pq.pop();
        vector<string> res(k);
        for (int i = k - 1; i >= 0; --i) {
            res[i] = pq.top().s;
            pq.pop();
        }
        return res;
    }
};