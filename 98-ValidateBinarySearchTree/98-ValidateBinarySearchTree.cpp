// Last updated: 5/17/2026, 5:52:28 PM
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
       vector<int> arr;
       inorder(root,arr); 
       int n=arr.size();
       for(int i=1;i<n;i++){
            if(arr[i-1]>arr[i] || arr[i-1]==arr[i]){
                return false;
            }
       }
        return true;
    }
    void inorder(TreeNode* root, vector<int> &arr){
        if(root==NULL)  return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
};