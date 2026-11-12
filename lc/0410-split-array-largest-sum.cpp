class Solution {
public:
    int splitArray(vector<int>& a, int k) {
        int lo = *max_element(a.begin(), a.end()), hi = accumulate(a.begin(), a.end(), 0), n = a.size();
        while (lo <= hi) {
            int sum = lo + (hi - lo) / 2, subarrs = 1;
            for (int i = 0, sub_sum = 0; i < n; i++) {
                if (sub_sum + a[i] > sum) {
                    sub_sum = 0;
                    subarrs++;
                }
                sub_sum += a[i];
            }
            // cout << sum << " " << subarrs << "\n";
            if (subarrs <= k) hi = sum - 1;
            else lo = sum + 1;
        }
        return lo;
    }
};