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
    // 1 <= Node.val <= 1e9
    pair<int, int> dfs(TreeNode* r) { // returns max, res cnt so far
        if (!r) return {0, 0};
        auto [left_max, left_res] = dfs(r->left);
        auto [right_max, right_res] = dfs(r->right);
        return {
            max(r->val, max(left_max, right_max)), (r->val >= max(left_max, right_max)) + left_res + right_res
        };
    }
    int countDominantNodes(TreeNode* r) {
        return dfs(r).second;
    }
};