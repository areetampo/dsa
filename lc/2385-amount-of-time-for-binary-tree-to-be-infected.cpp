/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public://m1 java code by making graph
    int res, target;
    pair<int, int> dfs(TreeNode* n) {
        if (!n) return {0, 0};
        pair<int, int> l = dfs(n->left);
        pair<int, int> r = dfs(n->right);
        cout << n->val << ", {" << l.first << " " << l.second << "}, {" << r.first << " " << r.second << "}" << endl;
        if (n->val == target) {
            res = max(res, max(l.first, r.first));
            return {1, 1};
        }
        if (l.second || r.second) {//non leaf node and target in left/right subtree
            res = max(res, l.first + r.first);
            return {1 + ((l.second) ? l.first : r.first), 1};
        }
        //both l,r 's second = 0 which means target not in that path
        return {max(l.first, r.first) + 1, 0};
    }
    int amountOfTime(TreeNode* n, int start) {
        target = start;
        res = 0;
        pair<int, int> l = dfs(n->left);
        pair<int, int> r = dfs(n->right);
        if (n->val == target) return max(l.first, r.first);
        return max(res, l.first + r.first);
    }
};