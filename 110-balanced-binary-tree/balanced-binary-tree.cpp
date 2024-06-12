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
    pair<bool, int> getBalancedHeight(TreeNode* root) {
        if(!root)
            return {true, 0};
        auto l = getBalancedHeight(root->left);

        if(!l.first)
            return {false, -1};

        auto r = getBalancedHeight(root->right);

        if(!r.first || abs(l.second - r.second) > 1)
            return {false, -1};
        return {true, max(l.second, r.second)+1};
    }
    int getH(TreeNode* root) {
        if(!root)
            return 0;

        int l = getH(root->left);
        if(l == -1)
            return -1;

        int r = getH(root->right);
        if(r == -1)
            return -1;
        
        if(abs(l-r) > 1)
            return -1;
        
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        return getH(root)!=-1;
        // return getBalancedHeight(root).first;
    }
};