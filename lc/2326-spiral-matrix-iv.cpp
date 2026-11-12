/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* c) {
        vector<vector<int>> res(n, vector<int>(m, -1));
        int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};
        int currIdx = 0, i = 0, j = 0;
        while (c) {
            // dbg(currIdx);
            for (; min(i, j) >= 0 && i < n && j < m && res [i][j] == -1 && c; c = c->next) {
                // dbg(i); dbg(j);
                res [i][j] = c->val;
                i += di [currIdx], j += dj [currIdx];
            }
            i -= di [currIdx], j -= dj [currIdx];//take one step back
            currIdx = (currIdx + 1) % 4;
            i += di [currIdx], j += dj [currIdx];//move to next sequence
            // dbg(res);
        }
        return res;
    }
};