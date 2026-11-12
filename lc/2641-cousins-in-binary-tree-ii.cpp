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
    TreeNode* replaceValueInTree(TreeNode* root) {
        //at each level: add those popped out nodes to buffer and calc its children's total sum, then traverse all nodes of buffer (which are of curr level) and update their left and right children's vals (if they exist) to sum - left - right;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<TreeNode*> buffer;
            int sz = q.size(), sum = 0;
            while (sz--) {
                auto n = q.front(); q.pop();
                buffer.push_back(n);
                if (n->left) sum += n->left->val, q.push(n->left);
                if (n->right) sum += n->right->val, q.push(n->right);
            }
            //curr level's children added in q and buffer has curr level, sum = sum of children
            for (auto n : buffer) {
                int l = n->left ? n->left->val : 0;
                int r = n->right ? n->right->val : 0;
                if (n->left) n->left->val = sum - l - r;
                if (n->right) n->right->val = sum - l - r;
            }
        }
        root->val = 0;
        return root;
    }
};