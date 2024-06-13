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
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;

        queue<pair<int, TreeNode*>> rem;
        rem.push({1, root});

        while(rem.size()){
            int level = rem.size();

            int offset = rem.front().first;
            int leftMost = 0;
            int rightMost = 0;

            while(level--){
                int i = rem.front().first - offset;
                auto node = rem.front().second;
                rem.pop();

                rightMost = i;

                if(node->left)
                    rem.push({(long long)i*2+1, node->left});
                if(node->right)
                    rem.push({(long long)i*2+2, node->right});
            }
            maxWidth = max(maxWidth, rightMost-leftMost+1);
        }

        return maxWidth;
    }
};