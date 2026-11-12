/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isUnivalTree(TreeNode root) {
        boolean val1 = false, val2 = false;
        if (root.left != null) {
            if (root.val == root.left.val)
            val1 = isUnivalTree(root.left);
            else val1 = false;
        }
        else val1 = true;

        if (root.right != null) {
            if (root.val == root.right.val)
            val2 = isUnivalTree(root.right);
            else val2 = false;
        }
        else val2 = true;

        return val1 && val2;
    }
}