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
    private static int staticK;
    public int kthSmallest(TreeNode root, int k) {
        staticK = k;
        return helper(root);
    }
    private int helper(TreeNode root) {
        if (root == null) return -1;
        int ans = helper(root.left);
        staticK--;
        if (staticK == 0) ans = root.val;
        if (staticK > 0) ans = helper(root.right);
        return ans;
    }
}