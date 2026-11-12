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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newList = nullptr; ListNode* curr = head; int s = 0;
        while (curr->next) {
            if (!curr->next->val) {
                if (!newList) {
                    newList = head;
                    newList->val = s;
                } else {
                    newList->next->val = s;
                    newList = newList->next;
                }
                s = 0;
            } else {
                s += curr->next->val;
            }
            curr = curr->next;
        }
        newList->next = nullptr;
        return head;
    }
};