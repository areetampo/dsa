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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();
        while (l1 != null) {
            s1.push(l1.val); 
            l1 = l1.next;
        }
        while (l2 != null) {
            s2.push(l2.val); 
            l2 = l2.next;
        }
        int val = s1.pop();
        val += s2.pop();
        ListNode ans = new ListNode(val % 10);
        int carry = val / 10;
        while (!s1.isEmpty() || !s2.isEmpty()) {
            val = 0;
            if (!s1.isEmpty()) {
                val += s1.pop();
            }
            if (!s2.isEmpty()) {
                val += s2.pop();
            }
            ListNode newNode = new ListNode((val + carry) % 10);
            carry = (val + carry) / 10;
            newNode.next = ans;
            ans = newNode;
        }
        if (carry != 0) {
            ListNode newNode = new ListNode(carry);
            newNode.next = ans;
            ans = newNode;
        }
        return ans;

    }
}