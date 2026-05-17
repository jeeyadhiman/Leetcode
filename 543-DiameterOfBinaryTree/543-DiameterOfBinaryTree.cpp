// Last updated: 5/17/2026, 5:51:46 PM
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
    int check(TreeNode* root){
        if(root==NULL) return 0;
        int left= check(root->left);
        int right= check(root->right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        if(root==NULL) return 0;
        int left=diameterOfBinaryTree(root->left);
        int right=diameterOfBinaryTree(root->right);
        return max({height(root), left, right}); 
    }
    int height(TreeNode* root){
        int h;
        int lefth=check(root->left);
        int righth=check(root->right);
        h=lefth+righth;
        return h;
    }
};