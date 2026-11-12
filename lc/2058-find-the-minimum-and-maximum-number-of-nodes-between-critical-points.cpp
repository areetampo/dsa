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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // min list size = 2
        ListNode* prev = head; ListNode* curr = head->next;
        int cnt = 2, first_crit = -1, prev_crit = -1, min_dist = 1e5;
        while (curr->next) {
            if (prev->val < curr->val && curr->val > curr->next->val ||
                prev->val > curr->val && curr->val < curr->next->val) {
                if (first_crit == -1) first_crit = cnt;
                if (prev_crit != -1) min_dist = min(min_dist, cnt - prev_crit);
                prev_crit = cnt;
            }
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        vector<int> res = {min_dist, prev_crit - first_crit};
        if (first_crit == prev_crit)
            res = {-1, -1};
        return res;
    }
};