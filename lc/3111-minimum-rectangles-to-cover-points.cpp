class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        vector<pair<int, int>> p;
        int n = points.size();
        for (auto x : points) {
            p.push_back({ x[0], x[1] });
        }
        sort(p.begin(), p.end());
        int res = 0;
        int i = 0;
        while (i < n) {
            int x = p[i].first, j = i;
            while (j + 1 < n && p[j + 1].first - x <= w) ++j;
            res++;
            i = j + 1;
        }
        return res;
    }
};