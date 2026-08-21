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
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> result;
        while (!q.empty()) {
            int n = static_cast<int>(q.size());
            vector<TreeNode*> level;
            for (int i = 0; i < n; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                if (i == 0) result.push_back(curr->val);
                if (curr->right) q.push(curr->right);
                if (curr->left) q.push(curr->left);
            }
        }
        return result;
    

    }
};
