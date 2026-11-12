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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> mp(nums.begin(), nums.end());
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while (curr) {
        if (mp.find(curr->val) != mp.end()) {
            if (prev) {
                prev->next = curr->next;
            } else {
                head = curr->next;
            }
        } else {
            prev = curr;
        }
        curr = curr->next;
    }
    ListNode* c = head;
    while (c) {
        cout << c->val << " ";
        c = c->next;
    }
    return head;
    }
};