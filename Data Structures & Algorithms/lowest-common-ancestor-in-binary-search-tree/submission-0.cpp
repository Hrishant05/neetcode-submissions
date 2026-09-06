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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        while(true){
            //CASE - 1, p and q on left side
            if(p->val < curr->val && q->val< curr->val){
                curr = curr->left;
            }

            //Case - 2, p & q on right side
            else if(p->val > curr->val && q->val > curr->val){
                curr = curr->right;
            }

            //Case 3 - answer node
            else{
                return curr;
            }
        }
        return nullptr;
    }
};
