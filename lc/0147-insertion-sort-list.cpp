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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* prevNode = head;
        ListNode* node = head->next;
        while (node) {
            if (prevNode->val > node->val) {
                ListNode* curr = head;
                ListNode* prevCurr = head;
                while (curr->val < node->val) {
                    prevCurr = curr;
                    curr = curr->next;
                }
                prevNode->next = node->next;
                node->next = curr;
                if (curr == head) {
                    head = node;
                } else {
                    prevCurr->next = node;
                }
                node = prevNode->next;
            } else {
                prevNode = node;
                node = node->next;
            }
        }
        return head;
    }
};