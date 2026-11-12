class Solution {
public:
    int maximumCandies(vector<int>& a, long long k) {
        // if (accumulate(a.begin(), a.end(), 0ll) < k) return 0;
        int lo = 1, hi = *max_element(a.begin(), a.end());
        while (lo <= hi) {
            int candy = lo + (hi - lo) / 2;
            long long t = k;
            for (int &i : a) t -= i / candy;
            // cout << candy << " " << t << "\n";
            if (t <= 0) lo = candy + 1;
            else hi = candy - 1;
        }
        return hi;
    }
};