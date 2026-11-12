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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if (root == null) return new ArrayList<>();

        List<List<Integer>> ans = new ArrayList<>();

        Queue<TreeNode> q = new LinkedList<>();
        q.add(null);
        q.add(root);

        while (!q.isEmpty()) {
            TreeNode peek = q.remove();//null removed
            if (q.isEmpty()) break;
            q.add(null);//null added back
            List<Integer> l = new ArrayList<>();
            while (q.peek() != null) {
                TreeNode node = q.remove();
                l.add(node.val);//nodes being removed left to right from q
                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);//nodes being added in q left to right
            }
            ans.add(l);
        }
        
        Collections.reverse(ans);
        return ans;
    }
}