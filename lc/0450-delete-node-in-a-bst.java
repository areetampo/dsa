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
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) return null;
        if (root.val == key) {
            if (root.right == null) return root.left;
            if (root.left == null) return root.right;
            if (root.left == null && root.right == null) return null;
            //when both left and right subtree exist
            TreeNode minInRightSubtree = root.right;
            while (minInRightSubtree.left != null) {
                minInRightSubtree = minInRightSubtree.left;
            }
            minInRightSubtree.left = root.left;
            root.left = null;
            return root.right;
        }
        root.left = deleteNode(root.left, key);
        root.right = deleteNode(root.right, key);
        return root;
    }
}