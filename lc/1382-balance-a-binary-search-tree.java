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
    public TreeNode balanceBST(TreeNode root) {
        if (root == null) {
            return null;
        }
        ArrayList<TreeNode> info = new ArrayList<>();
        inorder(root, info);
        return newBST(root, 0, info.size()-1, info);
    }
    public static TreeNode newBST(TreeNode root, int s, int e, ArrayList<TreeNode> info) {
        if (s > e) {
            return null;
        }
        int mid = s + (e-s)/2;
        root = info.get(mid);
        root.left = newBST(root.left, s, mid-1, info);
        root.right = newBST(root.right, mid+1, e, info);
        return root;
    }
    public static void inorder(TreeNode root, ArrayList<TreeNode> info) {
        if (root == null) {
            return;
        }
        inorder(root.left, info);
        info.add(root);
        inorder(root.right, info);
        return;
    }
}