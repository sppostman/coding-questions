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
    bool isValidBstUtil(TreeNode* root, long min, long max) {
        if(!root)
            return true;
        if(root->val > min && root->val < max){
            return isValidBstUtil(root->left, min, root->val) &&
                isValidBstUtil(root->right, root->val, max);
        }
        return false;
    }
    bool isValidBstInorder(TreeNode* root, long &prev) {
        if(!root)
            return true;
        if(!isValidBstInorder(root->left, prev))
            return false;
        if(root->val <= prev)
            return false;
        prev = root->val;
        return isValidBstInorder(root->right, prev);
    }
    bool isValidBST(TreeNode* root) {
        // return isValidBstUtil(root, LONG_MIN, LONG_MAX);
        long prev=LONG_MIN;
        return isValidBstInorder(root, prev);        
    }
};