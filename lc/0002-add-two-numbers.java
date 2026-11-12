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
        ListNode h1 = l1;
        ListNode h2 = l2;
        int carry = 0;
        ListNode ans = new ListNode(0);
        ListNode curr = ans;
        while (h1 != null && h2 != null) {
            curr.next = new ListNode((carry + h1.val + h2.val)%10);
            carry = (carry + h1.val + h2.val)/10;
            h1 = h1.next; h2 = h2.next;
            curr = curr.next;
        }
        while (h1 != null) {
            curr.next = new ListNode((carry + h1.val)%10);
            carry = (carry + h1.val)/10;
            h1 = h1.next;
            curr = curr.next;
        }
        while (h2 != null) {
            curr.next = new ListNode((carry + h2.val)%10);
            carry = (carry + h2.val)/10;
            h2 = h2.next;
            curr = curr.next;
        }
        if (carry != 0) curr.next = new ListNode(carry);
        return ans.next;
    }
}