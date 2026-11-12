class Solution {
public:
    int maxDistinctElements(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        long long min = v[0] - k; int res = 0;
        for (int i = 0; i < v.size(); i++) {
            if (min < v[i] - k) min = v[i] - k;
            if (abs(min - v[i]) <= k) {
                min++;
                res++;
            }
        }
        cout << res;
        // unordered_map<long long, int> m;
        // for (auto &i : v) m[i]++;
        return res;
    }
};