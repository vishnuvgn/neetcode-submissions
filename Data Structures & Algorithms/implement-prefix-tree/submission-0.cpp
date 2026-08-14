class PrefixTree {
private:
    struct Node {
        char value;
        vector<Node*> children;
        bool is_end;

        Node(char v) 
            : value(v), children(26,nullptr), is_end(false) {}
    };
    Node root;
public:
    PrefixTree() 
        : root(Node('\0')) {}
    
    void insert(string word) {
        Node* curr = &root;
        for (char c : word) {
            if (curr->children[c - 'a'] != nullptr) {
                curr = curr->children[c - 'a'];
            }
            else {
                Node* temp = new Node(c);
                curr->children[c - 'a'] = temp;
                curr = temp;
            }
        }
        curr->is_end = true;
    }
    
    bool search(string word) {
        Node* curr = &root;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) return false;
            curr = curr->children[c-'a'];
        }
        return curr->is_end;
    }
    
    bool startsWith(string prefix) {
        Node* curr = &root;
        for (char c : prefix) {
            if (curr->children[c - 'a'] == nullptr) return false;
            curr = curr->children[c-'a'];
        }
        return true;
    }
};
