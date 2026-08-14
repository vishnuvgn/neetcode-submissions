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
    bool isValidBST(TreeNode* root) {
        return recursive_search(INT_MIN, INT_MAX, root);
    }

    bool recursive_search(int min, int max, TreeNode* root) {
        if (!root) return true;
        if (root->val > min && root->val < max) {
            return recursive_search(min, root->val, root->left) && recursive_search(root->val, max, root->right);
        }
        return false;
    }

};
