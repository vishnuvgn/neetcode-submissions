/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        std::queue<TreeNode*> q;
        if (!root) return {};
        q.push(root);
        
        while (!q.empty()) {
            int n = static_cast<int>(q.size());
            for (int i = 0; i < n; ++i) {
                
                auto node = q.front();
                if (i == 0) {
                    result.push_back(node->val);
                }

                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            
                q.pop();
                
            }
        }
        return result;
    }
};
