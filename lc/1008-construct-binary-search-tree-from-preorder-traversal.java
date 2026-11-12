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
    public TreeNode bstFromPreorder(int[] preorder) {
        TreeNode root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.length; i++) {
            helper(i, preorder, root);
        }
        return root;
    }
    private TreeNode helper(int idx, int[] preorder, TreeNode curr) {
        if (curr == null) return new TreeNode(preorder[idx]);
        if (preorder[idx] > curr.val) curr.right = helper(idx, preorder, curr.right);
        else curr.left = helper(idx, preorder, curr.left);
        return curr;
    }
}