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
  ListNode* mergeInBetween(ListNode* l1, int a, int b, ListNode* l2) {
    ListNode* l2End = l2; while (l2End->next) l2End = l2End->next;
    ListNode* curr = l1; int sz = -1;
    ListNode* prev = nullptr;
    while (++sz != a) {
      prev = curr;
      curr = curr->next;
    }      
    while (sz++ != b) {
      curr = curr->next;
    }
    l2End->next = curr->next;
    if (prev) {
      prev->next = l2;
      return l1;
    }
    else return l2;//head to b deleted
  }
};