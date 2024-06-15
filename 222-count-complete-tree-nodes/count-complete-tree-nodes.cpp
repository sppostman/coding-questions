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
    int skewH(TreeNode* root, bool left){
        int h = 0;
        while(root){
            h++;
            if(left)
                root = root->left;
            else
                root = root->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
            
        int lh = skewH(root, true);
        int rh = skewH(root, false);
        
        if(lh == rh)
            return pow(2, lh)-1;
        
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};