// Last updated: 5/17/2026, 5:51:58 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((p->val < root->val && root->val< q->val )|| (q->val < root->val && root->val< p->val)){
            return root;
        }
        if(root->val== p->val||root->val== q->val){
            return root;
        }
        if(p->val > root->val && q -> val> root->val){
            root=lowestCommonAncestor(root->right,p,q);
        }
        else if(p->val< root->val && q->val< root->val){
            root=lowestCommonAncestor(root->left,p,q);
        }
        return root;
    }
};