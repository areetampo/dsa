class Solution {
public:
    int dfs(int curr, vector<vector<int>>& rfav, vector<bool>& vis) {
        vis[curr] = 1;
        int l = 0;
        for (int& next : rfav[curr]) {
            if (vis[next] == 0)
                l = max(l, dfs(next, rfav, vis));
        }
        return 1 + l;
    }
    int maximumInvitations(vector<int>& fav) {
        //https://youtu.be/LVV5_MOzdq4?si=y0ufo0oFtYZw7h7U
        //identify longest cycle (> 2 nodes)
        //or 2 len cycles with a path coming to the the 2 cycle nodes
        int n = fav.size();
        vector<vector<int>> rfav(n);
        vector<pair<int, int>> two_len_cycles;
        vector<bool> added_in_two_cycles(n, 0);
        for (int i = 0; i < n; i++) {
            rfav[fav[i]].push_back(i);
            if (i == fav[fav[i]] && added_in_two_cycles[i] == 0) {
                added_in_two_cycles[i] = 1;
                added_in_two_cycles[fav[i]] = 1;
                two_len_cycles.push_back({i, fav[i]});
            }
        }
        vector<bool> vis(n, 0);
        int longest_cycle = 0;
        vector<bool> cycle_counted(n, 0);
        for (int i = 0; i < n; i++) {
            if (vis[i] == 1) continue;
            int curr = i;
            while (vis[curr] == 0) {
                // cout << curr << " ";
                vis[curr] = 1;
                curr = fav[curr];
            }
            if (cycle_counted[curr] == 1) continue;
            cycle_counted[curr] = 1;
            int start = fav[curr], len = 1, previously_checked = 0;
            // cout << "\n" << curr << " ";
            while (start != curr) {
                if (cycle_counted[start] == 1) {previously_checked = 1; break;}
                cycle_counted[start] = 1;
                // cout << start << "." << cycle_counted[start] << " ";
                len++;
                start = fav[start];
            }
            if (previously_checked == 1) continue;
            longest_cycle = max(longest_cycle, len);
        }
        int two_len_cycle_group_nodes = 0;
        vis = vector<bool>(n, 0);
        for (auto& [x, y] : two_len_cycles) {
            int a = 0, b = 0;
            for (int& next : rfav[x]) {
                if (next == y) continue;
                a = max(a, dfs(next, rfav, vis));
            }
            for (int& next : rfav[y]) {
                if (next == x) continue;
                b = max(b, dfs(next, rfav, vis));
            }
            // cout << x << " " << y << " " << a << " " << b << "\n";
            two_len_cycle_group_nodes += 2 + a + b;
        }
        return max(two_len_cycle_group_nodes, longest_cycle);
    }
};