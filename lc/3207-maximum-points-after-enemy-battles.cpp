class Solution {
public:
    long long maximumPoints(vector<int>& v, int e) {
        sort(v.begin(), v.end()); int n = v.size();
        if (e < v[0]) return 0;
        long long E = e;
        for (int i = 1; i < n; i++) E += v[i];
        return E / v[0];
    }
};