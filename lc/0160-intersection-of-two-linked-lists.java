/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode a = headA;
        ListNode b = headB;
        int lenA = 0; int lenB = 0;
        while (a != null) {
            lenA++;
            a = a.next;
        }
        while (b != null) {
            lenB++;
            b = b.next;
        }
        a = headA; b = headB;
        int l = 1;
        if (lenA > lenB) {
            while (l != lenA-lenB+1) {
                a = a.next;
                l++;
            }
        }
        else {
            while (l != lenB-lenA+1) {
                b = b.next;
                l++;
            }
        }

        while (a != b) {
            a = a.next;
            b = b.next;
        }

        return a;//or b

        
    }
}