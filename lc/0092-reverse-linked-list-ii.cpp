/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {//l, r in [1,n]
        int size = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (++size != left) {
            prev = curr;
            curr = curr->next;
        }
        ListNode* nodeBeforeLeft = prev;
        ListNode* Left = curr;
        prev = NULL;
        ListNode* next = NULL;
        //right = n -> reverse entire list from left to end
        for (int i = left; i <= right; ++i) {//list reversed till right node (r <= n)
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        Left->next = curr;
        if (nodeBeforeLeft) nodeBeforeLeft->next = prev;
        return (left == 1) ? prev : head;//head changed
    }
};