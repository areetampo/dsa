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
    public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }
        return valid(root.left, root.val, Long.MIN_VALUE) && valid(root.right, Long.MAX_VALUE, root.val);
    }   
    public boolean valid(TreeNode root, long max, long min) {
        if (root == null) {
            return true;
        }
        if (root.val < max && root.val > min) {
            return valid(root.left, root.val, min) && valid(root.right, max, root.val);
        }
        else return false;
    }
}
//ALT (top to bottom using TreeNode null instead of long MAX,MIN_VAL)
// public boolean isValidBST(TreeNode root) {
//     if (root == null) {
//         return true;
//     }
//     return valid(root.left, root, null) && valid(root.right, null, root);
// }   
// public boolean valid(TreeNode root, TreeNode max, TreeNode min) {
//     if (root == null) {
//         return true;
//     }
//     if (min == null) {//in left
//         if (root.val < max.val)
//         return valid(root.left, root, min) && valid(root.right, max, root);
//         else return false;
//     }
//     else if (max == null) {//in right
//         if (min.val < root.val)
//         return valid(root.left, root, min) && valid(root.right, max, root);
//         else return false;
//     }
//     else {
//         if (root.val < max.val && root.val > min.val) 
//         return valid(root.left, root, min) && valid(root.right, max, root);
//         else return false;
//     }
// }

//ALT (from bottom to top approach)
// public static class Info {
//     boolean valid;
//     int max;
//     int min;
//     Info(boolean valid, int max, int min) {
//         this.valid = valid;
//         this.max = max;
//         this.min = min;
//     }
// }
// public static Info helper(TreeNode root) {
//     if (root == null) {
//         return new Info(true, Integer.MAX_VALUE, Integer.MIN_VALUE);
//     }
//     Info left = helper(root.left);
//     Info right = helper(root.right);

//     if (left.max == Integer.MAX_VALUE && left.min == Integer.MIN_VALUE && right.max == Integer.MAX_VALUE && 
//         right.min == Integer. MIN_VALUE)//both subtree null
//     return new Info(true, root.val, root.val);

//     else if (left.max == Integer.MAX_VALUE && left.min == Integer.MIN_VALUE)//left subtree null
//     return new Info(right.valid && (root.val < right.min), Math.max(root.val, right.max), Math.min(root.val, right.min));

//     else if (right.max == Integer.MAX_VALUE && right.min == Integer.MIN_VALUE)//right subtree null
//     return new Info(left.valid && (root.val > left.max), Math.max(root.val, left.max), Math.min(root.val, left.min));

//     else {
//         int max = Math.max(Math.max(left.max, right.max), root.val);
//         int min = Math.min(Math.min(left.min, right.min), root.val);
//         boolean valid = ((left.valid && right.valid) && (left.max < root.val) && (root.val < right.min));
//         return new Info(valid, max, min);
//     }
// }
// public boolean isValidBST(TreeNode root) {
//     Info i = helper(root);
//     return i.valid;
// }   