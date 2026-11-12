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
    //pre -> node left right
    //post -> left right node
    //all node vals are unique
    //root is pre[0] == po.back()
    //pre = [root, ...left..., ...right...]
    //po = [...left..., ...right..., root]
    //NOTE left's first val in pre is left's last in po and recursively breakdown
    //of each left/right subarr in to similar subtree
    //pre_e - pre_s == po_e - po_s (segment/subtree sizes equal)
    unordered_map<int, int> pre_val_index_in_po;
    TreeNode* build(vector<int>& pre, vector<int>& po, int pre_s, int pre_e, int po_s, int po_e) {
        // cout << "pre: " << pre_s << " " << pre_e << " po: " << po_s << " " << po_e << "\n";
        if (pre_s > pre_e || po_s > po_e) return nullptr;
        TreeNode* t = new TreeNode(pre[pre_s]);//pre[pre_s] == po[po_e] -> subtree root;
        if (pre_s == pre_e) return t;//or po_s == po_e
        int left_subtree_segement_start_pre = pre_s + 1,
            left_subtree_segement_end_po = pre_val_index_in_po[pre[pre_s + 1]],
            left_subtree_size = left_subtree_segement_end_po - po_s + 1,
            left_subtree_segement_end_pre = 
                left_subtree_segement_start_pre + left_subtree_size - 1,
            left_subtree_segement_start_po = po_s,
            right_subtree_segement_start_pre = left_subtree_segement_end_pre + 1,
            right_subtree_segement_end_pre = pre_e,
            right_subtree_segement_start_po = left_subtree_segement_end_po + 1,
            right_subtree_segement_end_po = po_e - 1;
        // cout << "l_pre: " << left_subtree_segement_start_pre << " " << left_subtree_segement_end_pre << "\n";
        // cout << "l_po: " << left_subtree_segement_start_po << " " << left_subtree_segement_end_po << "\n";
        // cout << "r_pre: " << right_subtree_segement_start_pre << " " << right_subtree_segement_end_pre << "\n";
        // cout << "r_po: " << right_subtree_segement_start_po << " " << right_subtree_segement_end_po << "\n" << "----------\n";
        t->left = build(pre, po, left_subtree_segement_start_pre, left_subtree_segement_end_pre, left_subtree_segement_start_po, left_subtree_segement_end_po);
        t->right = build(pre, po, right_subtree_segement_start_pre, right_subtree_segement_end_pre, right_subtree_segement_start_po, right_subtree_segement_end_po);
        return t;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& po) {
        for (int i = 0; i < pre.size(); i++) {
            for (int j = 0; j < po.size(); j++) {
                if (pre[i] == po[j]) {
                    pre_val_index_in_po[pre[i]] = j;
                    break;
                }
            }
        }
        return build(pre, po, 0, pre.size() - 1, 0, po.size() - 1);
    }
};