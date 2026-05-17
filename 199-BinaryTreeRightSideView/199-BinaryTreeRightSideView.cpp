// Last updated: 5/17/2026, 5:52:03 PM
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == NULL)
            return result;

        map<int, int> mp; // HD → value
        queue<pair<TreeNode*, int>> q;
        int level = 1;
        q.push({root, 0});
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto front = q.front();
                q.pop();

                TreeNode* node = front.first;
                int hd = front.second;
                if (mp.find(hd) == mp.end()) {
                    mp[hd] = node->val;
                }

                if (node->right)
                    q.push({node->right, level});

                if (node->left)
                    q.push({node->left, level});

            }
            level++;
        }

        for (auto it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};
