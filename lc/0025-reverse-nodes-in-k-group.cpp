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
    static inline ListNode* p = nullptr;
    static inline ListNode* c = nullptr;
    static inline ListNode* n = nullptr;
    static ListNode* reverse(ListNode* h, ListNode* t) {
        p = NULL;
        c = h;
        while (p != t) {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode* curr = head;
        ListNode* segmentHead = head;
        ListNode* nextHead = nullptr;
        ListNode* prevSegmentTail = nullptr;
        while (curr) {
            if (++cnt % k == 0) {
                nextHead = curr->next;
                if ((float)cnt/k == 1) {
                    prevSegmentTail = head;
                    head = reverse(segmentHead, curr);
                }
                else {
                    prevSegmentTail->next = reverse(segmentHead, curr);
                    prevSegmentTail = segmentHead;
                }
                prevSegmentTail->next = nextHead;
                segmentHead = nextHead;
            }
            curr = (cnt % k == 0) ? segmentHead : curr->next;
        }
        return head;
    }
};