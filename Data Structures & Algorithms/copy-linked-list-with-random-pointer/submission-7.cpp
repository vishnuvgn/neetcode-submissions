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
            Node* dupe = new Node(curr->val);
            Node* next_real = curr->next;
            curr->next = dupe;
            dupe->next = next_real;
            curr = curr->next->next;
        }

        curr = head;
        while (curr) {
            Node* dupe = curr->next;
            
            if (curr->random) {
                dupe->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;
        Node* new_head = curr->next;
        while (curr) {
            Node* dupe = curr->next;
            curr->next = curr->next->next;

            if (dupe->next) {
                dupe->next = dupe->next->next;
            }
            curr = curr->next;
        }
        return new_head;
    }
};
