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
    void pre(TreeNode* root, vector<int>&arr){
        if(root == NULL)    return;
        pre(root->left, arr);
        arr.push_back(root->val);
        pre(root->right, arr);
    }
    void preRectify(TreeNode* root, vector<int>&arr, int &i){
        if(root == NULL)    return;
        preRectify(root->left, arr, i);
        root->val=arr[i++];
        preRectify(root->right, arr, i);
    }
    void recoverTree(TreeNode* root) {
        vector<int> arr;
        pre(root,arr);
        sort(arr.begin(), arr.end());
        int i=0;
        preRectify(root, arr, i);
    }
};