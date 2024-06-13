/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findCount(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &lca) {
        if(!root)
            return 0;
        int count = 0;
        if(root == p)
            count++;
        if(root == q)
            count++;
        count += findCount(root->left, p, q, lca);
        count += findCount(root->right, p, q, lca);
        if(count == 2){
            lca = root;
            count = 0;
        }
        return count;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // TreeNode* lca = nullptr;
        // findCount(root, p, q, lca);
        // return lca;

        if(!root || root==p || root==q)
            return root;

        auto l = lowestCommonAncestor(root->left, p, q);
        auto r = lowestCommonAncestor(root->right, p, q);

        if(!l)
            return r;
        else if(!r)
            return l;
        else
            return root;
    }
};