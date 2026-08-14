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
        vector<int> result;
        dfs(root, result);
        return result[k-1];
    }

    void dfs(TreeNode* root, vector<int>& lst) {
        if (!root) return;
        dfs(root->left, lst);
        lst.push_back(root->val);
        dfs(root->right, lst);
    }
};