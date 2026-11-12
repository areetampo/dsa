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
  bool isPalindrome(ListNode* head) {
    ListNode* sPrev = nullptr;
    ListNode* s = head;
    ListNode* sNext = nullptr;
    ListNode* f = head;
    while (f && f->next) {
      f = f->next->next;
      sNext = s->next;
      s->next = sPrev;
      sPrev = s;
      s = sNext;
    }
    //for odd and even size ll and _ means there is no connection as next ptr broken
    // a b c_d e f                     reversed until c
    //       s     f
    //     p n
    // a b c_d e f g                   reversed until c
    //       s     f
    //     p n
    ListNode* s1 = sPrev;
    ListNode* s2 = (f) ? s->next : s;
    //to reverse back the reversed ll again as well (s1 list)
    sPrev = sNext;
    sNext = nullptr;
    while (s1) {
      if (s1->val != s2->val) return 0;
      sNext = s1->next;
      s1->next = sPrev;
      sPrev = s1;
      s1 = sNext;
      s2 = s2->next;
    }
    return 1;
  }
};
//1 2 2 1
//    s   f
//  p n