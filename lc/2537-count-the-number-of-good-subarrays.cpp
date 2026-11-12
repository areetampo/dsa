class Solution {
public:
    long long countGood(vector<int>& a, int k) {
        long long r = 0;
        unordered_map<int, int> m;
        int i = 0, j = 0;
        for (; j < a.size(); j++) {
            m[a[j]]++;
            k -= m[a[j]] - 1;//these many pairs are counted
            //remove excessive pairs by moving left (i) pointer
            // cout << j << " " << k << "\n";
            while (k + m[a[i]] - 1 <= 0) {
                k += m[a[i]] - 1;
                m[a[i]]--;
                i++;
                // cout << i << " ";
            }
            if (k <= 0) r += i + 1;
        }
        // cout << "\n" << i << " " << k << " " << r;
        if (k + m[a[i]] - 1 <= 0) {
            while (k + m[a[i]] - 1 <= 0) {
                k += m[a[i]] - 1;
                m[a[i]]--;
                i++;
            }
            // cout << "\n" << i << " " << k;
            if (k <= 0) r += i + 1;
        }
        return r;
    }
};