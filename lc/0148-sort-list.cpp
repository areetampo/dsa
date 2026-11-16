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
    ListNode* sortList(ListNode* h) {//merge sort O(nlogn)
        //base case
        if (!h || !h->next) return h;
        //merge
        ListNode* s = h;
        ListNode* prev = s;
        ListNode* f = s;
        while (f && f->next) {
            prev = s;
            s = s->next;
            f = f->next->next;
        }
        prev->next = NULL;
        h = sortList(h);
        s = sortList(s);
        //sort
        ListNode* x = new ListNode(0);
        ListNode* l = x;
        while (h && s) {
            if (h->val < s->val) {
                l = l->next = h;
                h = h->next;
            }
            else {
                l = l->next = s;
                s = s->next;
            }
        }
        l->next = (h) ? h : s;
        return x->next;
    }
};