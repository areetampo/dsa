class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& v, int k) {
        int res = 0, n = v.size();
        for (int i = 0, loop_again = 0; i < n; ) {
            int j = i;
            while (v[j % n] != v[(j + 1) % n])
                if (++j == (n - 1 + k) - 1) break;
            cout << i << " " << j << " " << j - i + 1 - k + 1 << "\n";
            res += max(j - i + 1 - k + 1, 0);
            i = j + 1;
        }
        return res;
    }
};