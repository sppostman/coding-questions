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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        bool leftToRight = true;
        queue<TreeNode*> rem;

        if(root)
            rem.push(root);

        while(rem.size() > 0){
            int nodes = rem.size();
            vector<int> thisLevelNodes(nodes);
            int i = leftToRight ? 0 : nodes-1;
            while(nodes--){
                auto currNode = rem.front();
                thisLevelNodes[i] = currNode->val;
                if(currNode->left)
                    rem.push(currNode->left);
                if(currNode->right)
                    rem.push(currNode->right);
                i += leftToRight ? 1 : -1;
                rem.pop();
            }
            leftToRight=!leftToRight;
            result.push_back(thisLevelNodes);
        }
        return result;
    }
};