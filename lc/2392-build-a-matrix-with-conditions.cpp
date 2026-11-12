class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
    vector<vector<int>> adj(k + 1, vector<int>(k + 1, 0));
    vector<int> indegree(k + 1, 0);
    //for row
    for (auto i : rc) {
        int above = i[0], below = i[1];
        adj[above][below] = 1;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            if (adj[i][j]) indegree[j]++;
        }
    }
    // dbg(indegree);
    queue<int> q; int r = 0; unordered_map<int, int> rowArrangement, colArrangement;
    vector<int> vis(k + 1, 0);
    for (int i = 1; i <= k; i++) if (indegree[i] == 0) {
        q.push(i);
        vis[i] = 1;
    }
    while (!q.empty()) {
        int node = q.front(); q.pop();
        rowArrangement[node] = r++;
        for (int i = 1; i <= k; i++) {
            if (adj[node][i] && !vis[i] && !--indegree[i]) {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    for (int i = 1; i <= k; i++) if (indegree[i] > 0) return {};
    //for col
    adj = vector<vector<int>>(k + 1, vector<int>(k + 1, 0));
    indegree = vector<int>(k + 1, 0);
    for (auto i : cc) {
        int left = i[0], right = i[1];
        adj[left][right] = 1;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            if (adj[i][j]) indegree[j]++;
        }
    }
    int c = 0;
    vis = vector<int>(k + 1, 0);
    for (int i = 1; i <= k; i++) if (indegree[i] == 0) {
        q.push(i);
        vis[i] = 1;
    }
    while (!q.empty()) {
        int node = q.front(); q.pop();
        colArrangement[node] = c++;
        for (int i = 1; i <= k; i++) {
            if (adj[node][i] && !vis[i] && !--indegree[i]) {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    for (int i = 1; i <= k; i++) if (indegree[i] > 0) return {};
    for (int i = 1; i <= k; i++) {
        if (!rowArrangement.count(i)) rowArrangement[i] = r++;
        if (!colArrangement.count(i)) colArrangement[i] = c++;
    }
    // dbg(rowArrangement); dbg(colArrangement);
    vector<vector<int>> res(k, vector<int>(k, 0));
    for (int i = 1; i <= k; i++) {
        res[rowArrangement[i]][colArrangement[i]] = i;
    }
    // dbg(res);
    return res;
    }
};