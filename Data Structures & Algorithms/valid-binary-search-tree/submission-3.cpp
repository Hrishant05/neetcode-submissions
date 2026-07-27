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
    bool isValid(TreeNode* root, int maxVal, int minVal){
        if(root==nullptr){
            return true;
        }
        
        if(root->val >= maxVal || (root->val)<=minVal) return false;
        return (isValid(root->left, root->val, minVal))&&(isValid(root->right, maxVal, root->val));

    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, 1001, -1001);
    }
};
