// Last updated: 5/17/2026, 5:52:23 PM
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int count = 1;
        queue<TreeNode*> q;
        if (root == NULL) {
            return result;
        }
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                if (count % 2 == 0) {
                    level.insert(level.begin(), node->val);
                } else {
                    level.push_back(node->val);
                }
            }
            count++;
            result.push_back(level);
        }
        return result;
    }
}
;