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
    public ListNode swapNodes(ListNode head, int k) {
        int totalNodes = 0;
        ListNode h = head;
        for (int i = 1; i < k; i++) {
            h = h.next;
        }    
        ListNode a = h;//h points to kth node now
        totalNodes = k-1;
        while (h != null) {
            totalNodes++;
            h = h.next;
        }
        h = head;
        for (int i = 1; i < totalNodes-k+1; i++) {
            h = h.next;
        }
        //now h is at the kth node from last;
        int temp = a.val;
        a.val = h.val;
        h.val = temp;
        return head;
    }

}