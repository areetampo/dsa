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
    int f(ListNode* n) {
        if (!n) return 0;
        int carry = f(n->next);
        int exp = n->val * 2 + carry;
        n->val = exp % 10;
        return exp / 10;
    }
    ListNode* doubleIt(ListNode* n, bool head = true) {
        //m-1
        //can use same func recursively with bool head = true initial argument and storing carry in bits if next node appropriately
        
        //m-2
        int carry = f(n);

        if (carry) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = n;
            return newHead;
        }
        return n;
    }
};