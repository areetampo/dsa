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
    //M-2 BFS
    public int minDepth(TreeNode root) {
        if (root == null) return 0;

        //create depthCounter, queue -> add null + root node
        int depth = 0; 
        Queue<TreeNode> q = new LinkedList<>();
        q.add(null);
        q.add(root);
        while (!q.isEmpty()) {
            TreeNode peek = q.remove();
            if (peek == null) {
                depth++;//adding nodes of next depth (peek's left, right) -> if they don't exist (peek = leaf) -> return current depth
                q.add(null);
            }
            else {//not null and valid node
                if (peek.left == null && peek.right == null) return depth;//first leaf node found = min depth 
                if (peek.left != null) q.add(peek.left);
                if (peek.right != null) q.add(peek.right);
            }
        }
        return depth;//never executed as a leaf node will be reached
    }
}

//M-1 BT Height - DFS (TLE)
//when calculating ht of bt, max ht from left/right picked, here pick min ht from left/rigth 

// if (root == null) return 0;
// int left = minDepth(root.left);
// int right = minDepth(root.right);
// if (left == 0) return 1 + right;
// else if (right == 0) return 1 + left;
// else return 1 + Math.min(minDepth(root.left), minDepth(root.right));