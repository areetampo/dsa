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
    bool check(TreeNode* r, ListNode* h) {//doing dfs here as well as there can be many paths (incomplete) [see eg 2]
        if (!h) return 1;
        if (!r) return 0;
        return h->val == r->val && (check(r->left, h->next) || check(r->right, h->next));
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        bool res = check(root, head);
        res |= isSubPath(head, root->left); 
        res |= isSubPath(head, root->right); 
        return res;
    }
};