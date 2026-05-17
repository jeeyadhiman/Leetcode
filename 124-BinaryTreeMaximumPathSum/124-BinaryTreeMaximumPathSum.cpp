// Last updated: 5/17/2026, 5:52:17 PM
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
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        PathSum(root,&sum);
        return sum;
    }
    int PathSum(TreeNode* root,int* sum){
        if (root==NULL){
            return 0;
        }
        int hleft=max(0,PathSum(root->left,sum));
        int hright=max(0,PathSum(root->right,sum));
        *sum=max(*sum,root->val+hleft+hright);
        return root->val+max(hleft,hright);
        
    }
};