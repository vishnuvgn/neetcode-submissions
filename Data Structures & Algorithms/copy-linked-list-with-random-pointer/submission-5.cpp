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
        Node* curr = head;
        unordered_map<Node*, Node*> mapping;
        while (curr) {
            Node* dupe = new Node(curr->val);
            mapping[curr] = dupe;
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            Node* dupe = mapping[curr];
            dupe->next = mapping[curr->next];
            dupe->random = mapping[curr->random];
            curr = curr->next;
        }
        return mapping[head];
    }
};
