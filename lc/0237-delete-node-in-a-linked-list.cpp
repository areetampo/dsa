/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* n) {
        //shifting of values
        // while (1) {
        //     n->val = n->next->val;
        //     if (!n->next->next) {
        //         n->next = nullptr;
        //         return;
        //     }
        //     n = n->next;
        // }   
        //interchange vals of n and n->next
        n->val = n->next->val;
        n->next = n->next->next;
    }
};