class Solution {
public:
    int findWinningPlayer(vector<int>& v, int k) {
        int i = 0, n = v.size(), prev = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && v[j] < v[i]) j++;
            int defeated = j - i - 1 + prev;
            if (defeated >= k) return i;
            prev = 1;
            i = j;
        }
        return distance(v.begin(), max_element(v.begin(), v.end()));
    }
};