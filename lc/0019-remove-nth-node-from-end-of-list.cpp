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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* curr = head;
    for (int i = 0; i < n && curr; ++i) {
      curr = curr->next;
    }
    if (!curr) return head->next;
    //curr lies at n + 1 node now
    ListNode* prevNEnd = head;//prev to nth node from end
    while (curr->next) {
      curr = curr->next;
      prevNEnd = prevNEnd->next;
    }
    prevNEnd->next = prevNEnd->next->next;
    return head;
  }
};