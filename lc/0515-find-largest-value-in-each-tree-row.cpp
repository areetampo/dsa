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
public:
    vector<int> largestValues(TreeNode* ro) {
        if (!ro) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(ro);
        while (!q.empty()) {
            int sz = q.size(), mx = INT_MIN;
            while (sz--) {
                auto t = q.front(); q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                mx = max(mx, t->val);
            }
            res.push_back(mx);
        }
        return res;
    }
};