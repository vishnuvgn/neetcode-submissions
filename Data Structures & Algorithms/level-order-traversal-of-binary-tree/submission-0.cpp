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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> result;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<TreeNode*> nodes;
            vector<int> temp;
            while (!q.empty()) {
                nodes.push_back(q.front());
                temp.push_back(q.front()->val);
                q.pop();
            }
            result.push_back(temp);
            for (auto& node: nodes) {
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return result;
     }
};
