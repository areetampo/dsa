class Solution {
public:
    struct f {
        int n;
        int freq;
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int &el : nums) ++m[el];
        priority_queue<f, vector<f>, decltype([](const f& a, const f& b){
            //undesired behaviour as we need lower freq at front to eliminate and get top k in end of pq
            //so a.freq < b.freq to sort in ascending but here writing a.freq > b.freq
            //same in q 692
            return a.freq > b.freq;
        })> pq;
        for (auto it = m.begin(); it != m.end(); ++it) {
            pq.push({it->first, it->second});
            if (pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().n);
            pq.pop();
        }
        return ans;
    }
};