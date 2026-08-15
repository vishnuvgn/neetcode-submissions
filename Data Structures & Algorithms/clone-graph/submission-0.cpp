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
        q.push(node);
        unordered_set<Node*> visited;
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            auto it = pairings.find(curr);
            if (it == pairings.end()) {
                Node* new_node = new Node(curr->val);
                pairings[curr] = new_node;
            }

            auto curr_copy = pairings[curr];

            for (auto neighbor : curr->neighbors) {
                auto it_2 = pairings.find(neighbor);
                if (it_2 == pairings.end()) {
                    Node* new_node = new Node(neighbor->val);
                    pairings[neighbor] = new_node;
                }
                auto neighbor_copy = pairings[neighbor];
                auto it_3 = visited.find(neighbor_copy);
                if (it_3 == visited.end()) {
                    curr_copy->neighbors.push_back(neighbor_copy);
                    neighbor_copy->neighbors.push_back(curr_copy);
                    q.push(neighbor);
                }
            }
            visited.insert(curr_copy);
        }
        return pairings[node];
    }
};
