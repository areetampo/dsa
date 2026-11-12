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
private: 
public:
    ListNode* mergeSort(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* x = new ListNode(0);
        ListNode* l = x;
        while (p1 && p2) {
            if (p1->val < p2 ->val) {
                l = l->next = p1;
                p1 = p1->next;
            }
            else {
                l = l->next = p2;
                p2 = p2->next;
            }
        }
        l->next = (p1) ? p1 : p2;
        return x->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        for (int i = 1; i < lists.size(); ++i) {
            lists[0] = mergeSort(lists[0], lists[i]);
        }
        return lists[0];
    }
};