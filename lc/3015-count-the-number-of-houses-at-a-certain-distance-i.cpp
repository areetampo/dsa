class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        //build graph
        vector<vector<int>> adj(n, vector<int>(0));//0 based indexing so use x-1, y-1
        adj[0].push_back(1);
        for (int i = 1; i < n-1; ++i) {
            adj[i].push_back(i-1);
            adj[i].push_back(i+1);
        }
        adj[n-1].push_back(n-2);
        if (x != y) {adj[x-1].push_back(y-1); adj[y-1].push_back(x-1);}
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < adj[i].size(); ++j) {
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << endl;
        // } cout << "dslak" << endl;
        //floydWarshall
        vector<vector<int>> v(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) v[i][i] = 0;//node n -> n 0 dist not in adj list
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < adj[i].size(); ++j) {
                int v1 = i;//vertex 1 = i
                int v2 = adj[i][j];//vertex 2 = values in vector adj[i]
                v[v1][v2] = 1;
            }
        }
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << v[i][j] << " ";
        //     }
        //     cout << endl;
        // } cout << "hjh" << endl;
        //i -> k -> j path
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (i == k) continue;
                for (int j = 0; j < n; ++j) {
                    if (j == k || i == j || v[i][k] == INT_MAX || v[k][j] == INT_MAX) continue;
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);//relaxation step
                }
            }
        }
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                //result[k] represents the total number of pairs of houses (a to b and b to a) such that the 
                //minimum streets required to reach one house from the other is k, which means that:
                //house a to b min dist v[a][b] = k and b to a min dist is also v[b][a] = k so all distances
                //k have pairs formed as v[][], since 1 based indexing, 0th means a dist of 1
                if (v[i][j] > 0 && v[i][j] != INT_MAX) ++res[v[i][j] - 1];
                // cout << v[i][j] << " ";
            }
            // cout << endl;
        }
        return res;
    }
};