class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> s(n), e(n);
        for (int i = 0; i < n; i++) {
            s[i] = intervals[i][0];
            e[i] = intervals[i][1];
        }

        sort(s.begin(), s.end());
        sort(e.begin(), e.end());

        long long ans = 0;
        int j = 0;

        // i = starts seen so far
        // j = ends strictly before current start
        for (int i = 0; i < n; i++) {
            while (j < n && e[j] < s[i])
                j++;

            // i previous intervals have started;
            // j of them have already ended.
            // Remaining i-j intervals intersect s[i].
            ans += i - j;
        }

        return ans;
    }
};