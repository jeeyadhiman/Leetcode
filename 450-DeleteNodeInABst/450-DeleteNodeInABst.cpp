// Last updated: 5/17/2026, 5:51:51 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == key) {
            return helper(root);
        }
        TreeNode* dummy = root;
        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left=helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            }
            else{
                if(root->right != NULL && root->right->val == key){
                    root->right=helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL) return root->right;
        else if (root->right==NULL) return root->left;
        TreeNode* rightChild= root->right;
        TreeNode* leftChild= findlast(root->left);
        leftChild->right= root->right;
        return root->left;
    }
    TreeNode* findlast(TreeNode* root){
        while(root->right !=NULL){
            root=root->right;
        }
        return root;
    }

};