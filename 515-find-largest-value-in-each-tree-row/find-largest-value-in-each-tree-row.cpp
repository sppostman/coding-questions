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
    vector<int> largestValues(TreeNode* root) {
        if(!root)   return {};

        vector<int> res;
        queue<TreeNode*> rem;
        rem.push(root);
        while(rem.size()){
            int level = rem.size();
            int maxhere = rem.front()->val;
            while(level--){
                TreeNode* curr = rem.front();
                rem.pop();
                maxhere = max(maxhere, curr->val);
                if(curr->left)
                    rem.push(curr->left);
                if(curr->right)
                    rem.push(curr->right);
            }
            res.push_back(maxhere);
        }
        return res;
    }
};