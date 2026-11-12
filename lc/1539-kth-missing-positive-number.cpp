class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0, h = n - 1, m = -1;
        while (l <= h) {
            m = l + (h - l) / 2;
            if (arr[m] - (m + 1) < k)
                l = m + 1;
            else
                h = m - 1;
        }
        if (h == -1) return k;
        return k - (arr[h] - (h+1)) + arr[h];
    }
};