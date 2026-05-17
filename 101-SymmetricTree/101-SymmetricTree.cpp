// Last updated: 5/17/2026, 5:52:26 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return mirror(root->left, root->right);
    }

    bool mirror(TreeNode* left, TreeNode* right) {
        // both null → symmetric
        if (left == NULL && right == NULL)
            return true;

        // one null → not symmetric
        if (left == NULL || right == NULL)
            return false;

        // values must be same
        if (left->val != right->val)
            return false;

        // check mirror sides
        return mirror(left->left, right->right) &&
               mirror(left->right, right->left);
    }
};
