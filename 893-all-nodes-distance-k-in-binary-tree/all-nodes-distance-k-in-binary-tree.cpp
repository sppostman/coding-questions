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
    void dfs(TreeNode* node, TreeNode* prev, int toGo, map<int,TreeNode*> parents, vector<int> &res) {
        if(!node)
            return;
        if(toGo < 0)
            return;
        if(toGo==0){
            res.push_back(node->val);
            return;
        }
        if(parents[node->val] != prev)
            dfs(parents[node->val], node, toGo-1, parents, res);
        if(node->left != prev)
            dfs(node->left, node, toGo-1, parents, res);
        if(node->right != prev)
            dfs(node->right, node, toGo-1, parents, res);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<int, TreeNode*> parents;
        queue<TreeNode*> rem;
        rem.push(root);
        parents[root->val] = nullptr;

        while(rem.size()){
            auto n = rem.front();
            rem.pop();
            if(n->left){
                rem.push(n->left);
                parents[n->left->val] = n;
            }
            if(n->right){
                rem.push(n->right);
                parents[n->right->val] = n;
            }
        }

        vector<int> result;
        dfs(target, nullptr, k, parents, result);
        return result;
    }
};