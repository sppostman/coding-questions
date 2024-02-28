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
    int findBottomLeftValue(TreeNode* root) {
        if(!root)   return -1;

        int latest = root->val;
        queue<TreeNode*> rem;
        rem.push(root);

        while(!rem.empty()){
            int level = rem.size();
            latest = rem.front()->val;
            while(level--){
                TreeNode *curr = rem.front();
                if(curr->left)  rem.push(curr->left);
                if(curr->right)  rem.push(curr->right);
                rem.pop();
            }
        }
        return latest;
    }
};