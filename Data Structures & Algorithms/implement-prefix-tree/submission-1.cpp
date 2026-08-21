class PrefixTree {
private:
    struct TreeNode {
        char value;
        bool is_end;
        unordered_map<char, TreeNode*> children;

        TreeNode(char v, bool end) : value(v), is_end(end), children({}) {}
    };

    TreeNode root;

public:
    PrefixTree() : root(' ', false) {}
    
    void insert(string word) {
        TreeNode* curr = &root;
        for (char c : word) {
            auto it = curr->children.find(c);
            if (it != curr->children.end()) {
                curr = it->second;
            }
            else {
                TreeNode* child = new TreeNode(c, false);
                curr->children[c] = child;
                curr = child;
            }
        }
        curr->is_end = true;
    }
    
    bool search(string word) {
        TreeNode* curr = &root;
        for (char c : word) {
            auto it = curr->children.find(c);
            if (it != curr->children.end()) {
                curr = it->second;
            }
            else {
                return false;
            }
        }
        return curr->is_end;
    }
    
    bool startsWith(string prefix) {
        TreeNode* curr = &root;
        for (char c : prefix) {
            auto it = curr->children.find(c);
            if (it != curr->children.end()) {
                curr = it->second;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
