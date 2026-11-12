class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& p, string s) {
        int n = p.size();
        vector<pair<int, char>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({ max(abs(p[i][0]), abs(p[i][1])), s[i] });
        }
        sort(v.begin(), v.end());
        // for (auto i : v) cout << i.first << "," << i.second << " ";
        unordered_set<char> set;
        int res = 0, i = 0;
        while (i < n) {
            int val = v[i].first;
            int j = i;
            int repeat = 0;
            while (j < n && v[j].first == val) {
                char c = v[j].second;
                if (set.find(c) != set.end()) {
                    repeat = 1; break;
                }
                set.insert(c);
                ++j;
            }
            if (repeat) break;
            res += j - i;
            // cout << i << " " << j << " " << res << endl;
            i = j;
        }
        return res;  
    }
};