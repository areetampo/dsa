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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        ArrayList<Integer> a1 = new ArrayList<>();
        ArrayList<Integer> a2 = new ArrayList<>();
        dfs(root1, a1);
        dfs(root2, a2);
        for (int i = 0; i < Math.min(a1.size(), a2.size()); i++) {
            if (a1.get(i) != a2.get(i)) return false;
        }
        return a1.size() == a2.size();
    }
    private void dfs(TreeNode root, ArrayList<Integer> a) {
        if (root.left == null && root.right == null) {
            a.add(root.val);
            return;
        }
        if (root.left == null) dfs(root.right, a);
        else if (root.right == null) dfs(root.left, a);
        else {
            dfs(root.left, a);
            dfs(root.right, a);
        }
    }
}