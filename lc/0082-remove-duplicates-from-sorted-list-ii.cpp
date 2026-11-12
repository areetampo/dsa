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
    void f(ListNode* h, ListNode** next, int* freq) {
        if (!h || !h->next) return;
        f(h->next, next, freq);
        if (h->val == h->next->val) {
            ++(*freq);
        }
        else if (*freq > 1) {
            h->next = *next;
            *freq = 1;
        }
        else *next = h->next;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        int i = 1;
        int* freq = &i;
        ListNode* n = NULL;
        ListNode** next = &n;
        f(head, next, freq);
        return (*freq > 1) ? *next : head;
    }
};