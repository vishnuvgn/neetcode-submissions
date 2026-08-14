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
    int kthSmallest(TreeNode* root, int k) {
        int answer = -1;
        dfs(root, k, answer);
        return answer;
    }

    void dfs(TreeNode* root, int& k, int& answer) {
        if (!root) return;
        
        dfs(root->left, k, answer);
        --k;
        if (k == 0) {
            answer = root->val;
        }
        dfs(root->right, k, answer);
    }

    
};