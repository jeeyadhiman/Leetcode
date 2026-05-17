// Last updated: 5/17/2026, 5:52:24 PM
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!= 0){
            vector<int> arr;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node= q.front();
                if (node == NULL) return result;
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                q.pop();
                arr.push_back(node->val);
            }
            result.push_back(arr);
        }
        return result;
    }
};