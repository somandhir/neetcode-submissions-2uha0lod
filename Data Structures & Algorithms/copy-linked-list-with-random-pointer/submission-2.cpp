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
        if (!head) return nullptr;
        Node* curr = head;

        while (curr) {
            Node* nxt = curr->next;
            Node* copy = new Node(curr->val);
            curr->next = copy;
            copy->next = nxt;
            curr = nxt;
        }
        curr = head;
        while (curr) {
            Node* cr = curr->random;
            Node* ccr = nullptr;
            if (cr) ccr = cr->next;
            Node* cn = curr->next;
            cn->random = ccr;
            curr = curr->next->next;
            // cout<<curr->val<<" ";
            // curr=curr->next->next;
        }
        curr = head;
        Node* copyHead = head->next;

        while (curr) {
            Node* copy = curr->next;
            curr->next = copy->next;
            if (copy->next) copy->next = copy->next->next;
            curr = curr->next;
        }
        return copyHead;
    }
};
