class Solution {
public:
    long long maximumSubarraySum(vector<int>& v, int k) {
        unordered_map<int, int> m;
        long long sum = 0;
        for (int i = 0; i < k; ++i) {
            m[v[i]]++;
            sum += v[i];
        }
        long long res = m.size() == k ? sum : 0;
        for (int i = k; i < v.size(); i++) {
            sum = sum + v[i] - v[i - k], m[v[i]]++;
            if (!--m[v[i - k]]) m.erase(v[i - k]);
            if (m.size() == k) res = max(res, sum);
        }
        return res;
    }
};