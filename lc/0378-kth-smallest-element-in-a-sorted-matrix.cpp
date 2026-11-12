class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {//method 2 using binary search
        int n = m.size();
        int lo = m[0][0], hi = m[n - 1][n - 1];
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            //find how many elements are <= mid
            int i = 0, j = n - 1, cnt = 0;
            while (i < n && j >= 0) {
                if (m[i][j] <= mid) {//curr row's elemnts taken
                    cnt += j + 1;
                    i++;//move down to next row same col
                } else {//[i][j] > mid so [i + 1][j] also > mid so move left in same row
                    j--;
                }   
            }
            if (cnt < k) lo = mid + 1;
            else hi = mid; 
        }
        return lo;
    }
};
// //in this approach need vis to prevent clashing of already taken next row/col elements
// //see sols for the approach where we satrt off by taking all the rows first el so each time we will be adding only teh next el of row hence no clashing and no vis needed in it
// int n = m.size();
// priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
// vector<vector<int>> vis(n, vector<int>(n, 0));
// pq.push({m[0][0], {0, 0}});
// vis[0][0] = 1;
// for (int i = 1; i < k; i++) {
//     auto top = pq.top(); pq.pop();
//     int r = top.second.first, c = top.second.second;
//     cout << top.first << endl;
//     if (r + 1 < n && vis[r + 1][c] == 0) {
//         pq.push({m[r + 1][c], {r + 1, c}});
//         vis[r + 1][c] = 1;
//     }
//     if (c + 1 < n && vis[r][c + 1] == 0) {
//         pq.push({m[r][c + 1], {r, c + 1}});
//         vis[r][c + 1] = 1;
//     }
// }
// return pq.top().first;