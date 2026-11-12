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
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null) return head;

        int size = 1;
        ListNode curr = head;
        while (curr.next != null) {
            curr = curr.next;
            size++;
        }
        ListNode tail = curr;

        k %= size;
        if (k == 0) return head;//edge case

        curr = head;
        for (int i = 1; i < size - k; i++) {//start = 1st = head -> size - k = total 1 + size-k-1 to traverse
            curr = curr.next;
        }

        ListNode newHead = curr.next;
        curr.next = null;//new tail
        tail.next = head;
        return newHead;
    }
}