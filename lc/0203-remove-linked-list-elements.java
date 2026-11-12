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
    public ListNode removeElements(ListNode head, int val) {
        if (head == null) return head;//size = 0
        ListNode curr = head;
        ListNode prev = head;//for when val is at tail
        while (curr != null) {
            while (curr.val == val) {
                if (curr.next == null) {//for tail
                    prev.next = null;
                    break;//curr stays at last node so while loop infinite
                }
                else {
                    curr.val = curr.next.val;
                    curr.next = curr.next.next;
                }
            }
            prev = curr;
            curr = curr.next;
        }
        if (head.val == val) return null;//for all nodes of ll == val, in end -> head left 
        return head;
    }
}