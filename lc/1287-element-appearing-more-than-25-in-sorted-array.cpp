class Solution {
private:
    static int lowerBound(const vector<int> &arr, int el) {
        int l = 0, h = arr.size() - 1, m = -1, ans = -1;
        while (l <= h) {
            m = (l+h) >> 1;
            if (arr[m] == el) {
                ans = m;
                h = m - 1;
            }
            else if (arr[m] > el) h = m - 1;
            else l = m + 1;
        }
        return ans;
    }
    static int upperBound(const vector<int> &arr, int el) {
        int l = 0, h = arr.size() - 1, m = -1, ans = -1;
        while (l <= h) {
            m = (l+h) >> 1;
            if (arr[m] == el) {
                ans = m;
                l = m + 1;
            }
            else if (arr[m] > el) h = m - 1;
            else l = m + 1;
        }
        return ans;
    }
public:
         int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), t = n / 4;

        for (int i = 0; i < n - t; i++) {
            if (arr[i] == arr[i + t]) {
                return arr[i];
            }
        }
        return -1;
    }
};