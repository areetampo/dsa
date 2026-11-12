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
    vector<int> sizes;
    int dfs(TreeNode* n) {
        if (n == nullptr) return 0;
        int l = dfs(n->left), r = dfs(n->right);
        if (l != r || l == -1 || r == -1) return -1;
        sizes.push_back(l + r + 1);//l == r
        return l + r + 1;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        sizes = {};
        dfs(root);
        sort(sizes.rbegin(), sizes.rend());
        return sizes.size() < k ? -1 : sizes[k - 1];
    }
};