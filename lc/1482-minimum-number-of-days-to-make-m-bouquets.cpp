class Solution {
public:
    bool canMake(vector<int>& v, int groups, int groupSize, int mx) {
        int n = v.size();
        for (int i = 0; i <= n - groupSize; ) {
            int j = i;
            while (j < i + groupSize && v[j] <= mx) j++;
            if (j == i + groupSize) {
                groups--;
                i += groupSize;
            } else i++;
        }
        return groups <= 0;
    }
    int minDays(vector<int>& v, int m, int k) {
        if ((long long)m * k > v.size()) return -1;
        int l = 1, h = 1e9;
        while (l <= h) {
            int mid = (l + h) >> 1;
            if (canMake(v, m, k, mid)) h = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};