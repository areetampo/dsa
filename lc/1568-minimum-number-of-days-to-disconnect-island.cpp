class Solution {
public:
    vector<int> dx = { 1,-1,0,0 }, dy = { 0,0,1,-1 }; int t;
void dfsArticulationPoint(int i, int j, int parI, int parJ, vector<vector<int>>& g, vector<vector<int>>& vis, vector<vector<int>>& dt, vector<vector<int>>& ldt, int* apExits) {
    // dbg(i); dbg(j);
    vis[i][j] = 1;
    dt[i][j] = ldt[i][j] = ++t;
    int children = 0;
    for (int x = 0; x < 4; x++) {
        int ni = i + dx[x], nj = j + dy[x];
        if (ni == parI && nj == parJ || ni < 0 || nj < 0 || ni >= g.size() || nj >= g[0].size() || !g[ni][nj])
            continue;
        if (!vis[ni][nj]) {
            dfsArticulationPoint(ni, nj, i, j, g, vis, dt, ldt, apExits);
            ldt[i][j] = min(ldt[i][j], ldt[ni][nj]);
            if (parI != -1 && parJ != -1 && dt[i][j] <= ldt[ni][nj]) {
                *apExits = 1;
            }
            children++;
        } else {
            ldt[i][j] = min(ldt[i][j], dt[ni][nj]);
        }
    }
    if (parI == -1 && parJ == -1 && children != 1) *apExits = 1;//root itself (and if children > 1 then
    //definitely ap but if children = 0 that means a single island cell and if total islands = 1 that menas its the only = 1 cell in the grid and must be removed to not have exactly 1 island in the grid [teh task is to have 0 or > 1 islands])
}
int minDays(vector<vector<int>>& g) {
    t = 0;
    int n = g.size(), m = g[0].size(), islands = 0, apExists = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0)), discoveryTime(n, vector<int>(m, 0)), lowestDiscoveryTime(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] && !vis[i][j]) {
                dfsArticulationPoint(i, j, -1, -1, g, vis, discoveryTime, lowestDiscoveryTime, &apExists);
                islands++;
            }
        }
    }
    // dbg(islands);
    return islands == 1 ? apExists ? 1 : 2 : 0;
}
};