// Last updated: 5/17/2026, 5:51:59 PM
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
        vector<int> arr;
        if(root==NULL){
            return -1;
        }
        inorder(root,arr);
        return arr[k-1];
    }
    void inorder(TreeNode* root, vector<int>& arr) {
    if(root == NULL) return;
    inorder(root->left, arr); 
    arr.push_back(root->val);     
    inorder(root->right, arr);     
}

};