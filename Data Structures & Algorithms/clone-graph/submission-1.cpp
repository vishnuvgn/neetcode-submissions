/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> pairings;
        queue<Node*> q;

        pairings[node] = new Node(node->val);
        q.push(node);
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (auto neighbor : curr->neighbors) {
                auto it_2 = pairings.find(neighbor);
                if (it_2 == pairings.end()) {
                    Node* new_node = new Node(neighbor->val);
                    pairings[neighbor] = new_node;
                    q.push(neighbor);
                }
                pairings[curr]->neighbors.push_back(pairings[neighbor]);
            }
        }
        return pairings[node];
    }
};
