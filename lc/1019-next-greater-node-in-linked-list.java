/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[] nextLargerNodes(ListNode head) {
        Stack<Integer> s = new Stack<>();
        return traverse(head, 0, s);
    }
    private static int[] traverse(ListNode curr, int size, Stack<Integer> s) {
        if (curr == null) {
            return new int[size];
        }
        int[] ans = traverse(curr.next, size + 1, s);
        while (!s.isEmpty() && s.peek() <= curr.val) {
            s.pop();
        }
        ans[size] = s.isEmpty() ? 0 : s.peek() ;
        s.push(curr.val);
        return ans;
    }
}