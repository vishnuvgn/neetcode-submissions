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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> p_queue;
        queue<TreeNode*> q_queue;
        p_queue.push(p);
        q_queue.push(q);

        while (!p_queue.empty() && !q_queue.empty()) {
            auto p_node = p_queue.front();
            p_queue.pop();
            auto q_node = q_queue.front();
            q_queue.pop();

            if (p_node && q_node) {
                if (p_node->val != q_node->val) return false;
                
                p_queue.push(p_node->left);
                p_queue.push(p_node->right);
                
                q_queue.push(q_node->left);
                q_queue.push(q_node->right);
            }
            else if (!p_node && !q_node) continue;
            else return false;
        }
        return p_queue.empty() && q_queue.empty();
    }
};
