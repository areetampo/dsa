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
    public ListNode oddEvenList(ListNode head) {
        ListNode h = head;
        int size = 1;
        if (h == null || h.next == null || h.next.next == null) return h;
        ListNode t = h;
        while (t.next != null) {
            size++;
            t = t.next;
        }

        for (int i = 0; i < size/2; i++) {
            t.next = h.next;
            t = t.next;
            h.next = h.next.next;
            h = h.next;
        }
        t.next = null;

        return head;
    }
}