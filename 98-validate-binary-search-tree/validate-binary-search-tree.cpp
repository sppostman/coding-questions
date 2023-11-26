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
    // bool isvalid(TreeNode* root, long lb, long ub){
    //     if(!root)
    //         return true;
    //     if(root->val >= ub || root->val <= lb){
    //         return false;
    //     }
    //     return isvalid(root->left, lb, root->val) &&
    //         isvalid(root->right, root->val, ub);
    // }

    bool isvalid(TreeNode* root, TreeNode* &prev){
        if(!root)
            return true;

        if(!isvalid(root->left, prev))
            return false;
        
        if(prev && prev->val >= root->val)
            return false;
            
        prev = root;
        return isvalid(root->right, prev);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return isvalid(root, prev);
    }
};