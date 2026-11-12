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
  ListNode* removeZeroSumSublists(ListNode* head) {
    unordered_map<int, ListNode*> m; m[0] = new ListNode(0);//temp head
    m[0]->next = head;

    ListNode* curr = head;
    int sum = 0;//prefix sum

    while (curr) {
      sum += curr->val;
      if (m.find(sum) != m.end()) {
        //del from hm b/w start and curr->next otherwise clashes eg dry run 3,2,-3,-2,5,5,-5
        ListNode* start = m[sum]->next;
        int p = sum + start->val;
        while (start->next && p != sum) {
          m.erase(p);
          start = start->next;
          p += start->val;
        }
        m[sum]->next = curr->next;//assigning next pointer after deletion of 0 sum seq
        //only put when presum not found otherwise stays mapped to the leftmost node for deletion seq
      } else m[sum] = curr;
      curr = curr->next;
    }

    return m[0]->next;//next of the temp head
  }
};