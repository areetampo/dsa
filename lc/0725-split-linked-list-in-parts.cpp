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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if (!head) return vector<ListNode*>(k, nullptr);
        vector<ListNode*> res;
        int n = 1; ListNode* c = head;
        while (c->next) n++, c = c->next;
        c = head;
        int extraNodeInHowManyLists = n % k, listSz = n / k;
        // cout << listSz << " " << extraNodeInHowManyLists << endl;
        while (c) {
            res.push_back(c);
            int cnt = 0;
            while (++cnt < listSz + (extraNodeInHowManyLists > 0)) c = c->next;
            ListNode* t = c->next;
            c->next = nullptr;
            c = t;
            --extraNodeInHowManyLists;
        }
        for (int i = n; i < k; i++) res.push_back(nullptr);
        return res;
    }
};