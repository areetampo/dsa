class Solution {
public:
    int mergeSort(int s, int e, vector<int>& v) {
        if (s == e) return 0;
        int m = (s + e) >> 1;
        int res = mergeSort(s, m, v) + mergeSort(m + 1, e, v);
        //compute res
        for (int j = m + 1, i = s; j <= e && i <= m; ) {
            if (v[i] / 2.0 > v[j]) {
                res += m - i + 1;
                j++;
            } else i++;
        }
        //merge
        int sz = e - s + 1;
        int t[sz];
        int i = s, j = m + 1, idx = 0;
        while (i <= m && j <= e) t[idx++] = v[v[i] > v[j] ? j++ : i++];
        while (i <= m) t[idx++] = v[i++];
        while (j <= e) t[idx++] = v[j++];
        for (int x = 0; x < sz; x++) v[x + s] = t[x];
        return res;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(0, nums.size() - 1, nums);
    }
};