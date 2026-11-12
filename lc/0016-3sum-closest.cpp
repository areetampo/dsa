class Solution {
public:
    int threeSumClosest(vector<int>& v, int t) {
        int res = v[0] + v[1] + v[2], n = v.size();
        sort(v.begin(), v.end());
        for (int i = 0; i < n-2; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int s = v[i] + v[j] + v[k];
                if (s == t) return s;
                if (abs(res - t) > abs(s - t)) res = s;
                if (s > t) --k;
                else ++j;
            }
        }
        return res;
    }
};