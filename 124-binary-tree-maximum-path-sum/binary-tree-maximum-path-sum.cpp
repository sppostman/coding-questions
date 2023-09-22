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
    int find(TreeNode* root, int &maxsum){
        if(!root)   return 0;

        int lpart = max(find(root->left, maxsum), 0);
        int rpart = max(find(root->right, maxsum), 0);

        maxsum = max(lpart + rpart + root->val, maxsum);
        return max(lpart + root->val, rpart + root->val);
    }
    int maxPathSum(TreeNode* root) {
        int maxsum = root->val;
        find(root, maxsum);
        return maxsum;
    }
};