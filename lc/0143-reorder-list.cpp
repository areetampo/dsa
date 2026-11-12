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
public://slow always at n/2 + 1
  //a b c d
  //    s   f
  //a b c d e
  //    s   f
  ListNode* rev(ListNode* c) {
    ListNode* p = nullptr;
    ListNode* n = nullptr;
    while (c) {
      n = c->next;
      c->next = p;
      p = c;
      c = n;
    }
    return p;
  }
  void reorderList(ListNode* head) {
    ListNode* s = head;
    ListNode* f = s;
    while (f && f->next) {
      s = s->next;
      f = f->next->next;
    }
    ListNode* s1 = head; 
    ListNode* s2 = rev(s);//at tail
    ListNode* t1 = nullptr;//temps 
    ListNode* t2 = nullptr; 
    while (s1->next && s2->next) {
      t1 = s1->next;
      t2 = s2->next;
      s1->next = s2;
      s2->next = t1;
      s1 = t1;
      s2 = t2;
    }
  }
};