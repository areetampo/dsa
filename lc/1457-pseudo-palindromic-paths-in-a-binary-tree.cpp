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
    int isPseudoPalindrome(unordered_map<int, int> m) {
        int oddFreqs = 0, total = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            // cout << it->first << " " << it->second << ", ";
            total += it->second;
            if (it->second % 2) ++oddFreqs;
        }
        // cout << endl;
        return (total % 2 && oddFreqs == 1) || (!(total % 2) && !oddFreqs);
    }
    int dfs(TreeNode* r, unordered_map<int, int>& m) {
        int res = 0;
        m[r->val]++;
        if (!r->left && !r->right) {
            res = isPseudoPalindrome(m);
        } else {
            if (r->left) res += dfs(r->left, m);
            if (r->right) res += dfs(r->right, m);
        }
        if (--m[r->val] == 0) m.erase(r->val);
        return res;
    }
    int pseudoPalindromicPaths (TreeNode* r) {
        unordered_map<int, int> m;
        return dfs(r, m);
    }
};