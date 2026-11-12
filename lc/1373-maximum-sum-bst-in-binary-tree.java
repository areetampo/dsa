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
    private static class Info {
        boolean valid;
        int sum;
        int max;
        int min;
        Info(boolean valid, int sum, int max, int min) {
            this.valid = valid;
            this.sum = sum;
            this.max = max;
            this.min = min;
        }
    }
    public int maxSumBST(TreeNode root) {
        int[] ans = new int[1];
        help(root, ans);
        return ans[0];
    }
    private static Info help(TreeNode root, int[] ans) {
        if (root == null) {
            return new Info(true, 0, Integer.MAX_VALUE, Integer.MAX_VALUE);
        }
        Info left = help(root.left, ans);
        Info right = help(root.right, ans);
        if (left.max == Integer.MAX_VALUE && right.max == Integer.MAX_VALUE) {//both child null
            ans[0] = Math.max(ans[0], root.val);//leaf node always a bst
            return new Info(true, root.val, root.val, root.val);
        }
        else if (left.max == Integer.MAX_VALUE) {//left null
            if (right.valid && root.val < right.min) ans[0] = Math.max(ans[0], root.val + right.sum);
            return new Info(right.valid && root.val < right.min, right.sum + root.val, Math.max(root.val, right.max), 
            Math.min(root.val, right.min));
        }
        else if (right.max == Integer.MAX_VALUE) {//right null
            if (left.valid && root.val > left.max) ans[0] = Math.max(ans[0], root.val + left.sum);
            return new Info(left.valid && root.val > left.max, left.sum + root.val, Math.max(root.val, left.max), 
            Math.min(root.val, left.min));
        }
        else {//both child not null
            boolean valid = left.valid && right.valid && root.val > left.max && root.val < right.min;
            if (valid) ans[0] = Math.max(ans[0], root.val + left.sum + right.sum);
            return new Info(valid, right.sum + left.sum + root.val, Math.max(root.val, Math.max(left.max, right.max)),
            Math.min(root.val, Math.min(left.min, right.min)));
        }
    }
}