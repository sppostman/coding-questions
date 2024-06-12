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
    int dfs(TreeNode* root, int &maxPath) {
        if(!root)
            return 0;
        int l = dfs(root->left, maxPath);
        int r = dfs(root->right, maxPath);

        maxPath = max({maxPath, l+r+root->val, root->val, l+root->val, r+root->val});
        return max({root->val, l+root->val, r+root->val});
    }
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        dfs(root, maxPath);
        return maxPath;
    }
};