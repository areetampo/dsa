class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& g, int n = 2, int m = 3) {
        int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
        queue<vector<vector<int>>> q;
        unordered_set<string> vis;
        q.push(g);
        int res = -1;
        while (!q.empty()) {
            res++;
            int sz = q.size();
            while (sz--) {
                auto t = q.front(); q.pop();
                string s = "";
                for (auto &i : t) for (int &j : i) s += j + '0';
                // cout << s << "\n";
                if (s == "123450") return res;
                if (vis.find(s) != vis.end()) continue;
                vis.insert(s);
                int x, y;
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++) if (t[i][j] == 0) x = i, y = j;
                for (int i = 0; i < 4; i++) {
                    int new_x = x + dx[i], new_y = y + dy[i];
                    if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m) {
                        swap(t[x][y], t[new_x][new_y]);
                        s = "";
                        for (auto &i : t) for (int &j : i) s += j + '0';
                        if (vis.find(s) == vis.end()) {
                            // cout << s << ",";
                            q.push(t);
                        }
                        swap(t[x][y], t[new_x][new_y]);
                    }
                }
                // cout << "\n";
            }
            // cout << "--\n";
        }
        return -1;
    }
};