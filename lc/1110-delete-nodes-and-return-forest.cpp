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
    TreeNode* f(TreeNode* ro, unordered_set<int>& del, vector<TreeNode*>& res) {
        if (!ro) return ro;
        TreeNode* l = f(ro->left, del, res);
        TreeNode* r = f(ro->right, del, res);
        ro->left = l;
        ro->right = r;
        if (del.count(ro->val)) {
            ro = nullptr;
            if (l) res.push_back(l);
            if (r) res.push_back(r);
        }
        return ro;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;
        root = f(root, del, res);
        root = f(root, del, res);
        if (root) res.push_back(root);
        return res;
    }
};