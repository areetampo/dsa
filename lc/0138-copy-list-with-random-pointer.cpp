/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        //creating deep copy nodes
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = next;
        }
        //adjusting random pointer
        curr = head;
        while (curr) {
            if (curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        //separating deep copy nodes to form their own ll
        curr = head;
        Node* ansHead = curr->next;
        Node* t = ansHead;
        curr->next = curr->next->next;
        curr = curr->next;
        while (curr) {
            t->next = curr->next;
            t = t->next;
            curr->next = curr->next->next;
            curr = curr->next;
        }
        return ansHead;
    }
};