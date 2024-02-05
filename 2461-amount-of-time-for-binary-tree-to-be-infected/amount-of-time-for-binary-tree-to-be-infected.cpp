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
    TreeNode* find(TreeNode* root, int x, unordered_map<int, TreeNode*> &parents){
        if(root==nullptr)
            return nullptr;

        if(root->val == x)
            return root;

        if(root->left)
            parents[root->left->val] = root;
        if(root->right)
            parents[root->right->val] = root;

        auto lhalf = find(root->left, x,parents);
        if(lhalf)   return lhalf;

        return find(root->right, x, parents);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, TreeNode*> parents;

        queue<TreeNode*> rem;
        unordered_map<int, bool> visited;
        TreeNode* found = find(root, start, parents);
        visited[found->val] = true;
        rem.push(found);

        int steps = 0;
        while(!rem.empty()){
            int atthislevel = rem.size();
            while(atthislevel--){
                TreeNode* curr = rem.front();
                rem.pop();
                
                if(curr->left && !visited[curr->left->val]){
                    rem.push(curr->left);
                    parents[curr->left->val] = curr;
                    visited[curr->left->val] = true;
                }
                if(curr->right && !visited[curr->right->val]){
                    rem.push(curr->right);
                    parents[curr->right->val] = curr;
                    visited[curr->right->val] = true;
                }
                if(parents[curr->val] && !visited[parents[curr->val]->val]){
                    rem.push(parents[curr->val]);
                    visited[parents[curr->val]->val] = true;
                }
            }
            if(!rem.empty())
                steps++;
        }

        return steps;

    }
    
};
        

