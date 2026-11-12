class Solution {
public:
    int can(vector<int>& v, int max_diff) {
        int pairs = 0;
        for (int i = 0; i < v.size() - 1; ) {
            // cout << v[i] << " " << v[i + 1] << "...\n";
            if (abs(v[i] - v[i + 1]) <= max_diff) pairs++, i += 2;
            else i++;
        }
        // cout << pairs << " pairs\n";
        return pairs;
    }
    int minimizeMax(vector<int>& v, int p) {
        sort(v.begin(), v.end());
        // for (int &i : v) cout << i << " "; cout << "\n";
        int lo = 0, hi = v.back() - v[0];
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            // cout << mid << " mx\n";
            //can make p pairs with max diff <= mid
            if (can(v, mid) >= p) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    }
};