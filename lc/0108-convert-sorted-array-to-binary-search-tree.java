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
    public TreeNode sortedArrayToBST(int[] nums) {
        return help(null, 0, nums.length-1, nums);
    }
    public TreeNode help(TreeNode root, int s, int e, int[] nums) {
        if (s > e) {
            return null;
        }
        int mid = s + (e-s)/2;
        root = new TreeNode(nums[mid], null, null);
        root.left = help(root, s, mid-1, nums);
        root.right = help(root, mid+1, e, nums);
        return root;
    }
}