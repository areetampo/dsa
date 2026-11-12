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
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode temp = head.next;
        head.next = temp.next;
        temp.next = head;
        head = temp;

        ListNode prev = head.next;
        ListNode n1 = prev.next;
        ListNode n2 = null;
        while (n1 != null && n1.next != null) {
            n2 = n1.next;
            temp = n2.next;
            prev.next = n2;
            n2.next = n1;
            n1.next = temp;
            prev = n1;
            n1 = prev.next;
        }
        
        return head;
    }
}