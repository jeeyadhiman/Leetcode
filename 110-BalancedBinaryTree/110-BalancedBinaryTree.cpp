// Last updated: 5/17/2026, 5:52:20 PM
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
    bool calc(TreeNode*root,int* lefth,int *righth){
        if(root->left==NULL){
            *lefth=0;
        }
        if(root->right==NULL){
            *righth=0;
        }
        if(root->left!=NULL){
            *lefth=maxDepth(root->left);
        }
        if(root->right!=NULL){
            *righth=maxDepth(root->right);
        }
        if (abs(*lefth - *righth) <= 1) {
            return true;
        }
        return false ;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int left,right;
        bool result=calc(root,&left,&right);
        if (!result) return false;
        if(!isBalanced(root->left)) return false;
if(!isBalanced(root->right)) return false;
return true;
    }
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int max=0;
        if (root == NULL) return max;
        while(q.size()!= 0){
            max++;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node= q.front();
                if (node == NULL) return max;
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                q.pop();
            }
        }
        return max;
    }
};