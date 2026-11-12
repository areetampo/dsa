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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        dfs(0, root, ans);
        return ans;
    }
    private static void dfs(int depth, TreeNode curr, List<Integer> ans) {
        if (curr == null) return;
        if (ans.size()-1 < depth) {
            ans.add(curr.val);
        }
        dfs(depth + 1, curr.right, ans);
        dfs(depth + 1, curr.left, ans);
    }
}