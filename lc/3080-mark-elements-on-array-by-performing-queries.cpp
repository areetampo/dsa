class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& q) {
        vector<pair<int, int>> v;
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            v.push_back({ nums[i], i });
            sum += nums[i];
        }
        sort(v.begin(), v.end());
        unordered_set<int> deletedIdx;
        int i = 0;
        vector<long long> res(q.size(), 0);
        int resIdx = 0;
        for (auto& Q : q) {
            int qIdx = Q[0], totalDel = Q[1];
            if (deletedIdx.find(qIdx) == deletedIdx.end()) {
                deletedIdx.insert(qIdx);
                sum -= nums[qIdx];
            }
            while (i < nums.size() && totalDel--) {
                int val = v[i].first, idx = v[i].second;
                if (deletedIdx.find(idx) != deletedIdx.end()) totalDel++;
                else {
                    sum -= val;
                    deletedIdx.insert(idx);
                }
                ++i;
            }
            res[resIdx++] = sum;
            if (i == nums.size()) break;
        }
        return res;
    }
};