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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        int currSum = 0;
        if(root->left){
            if(!root->left->left && !root->left->right){
                currSum+=root->left->val;
             }
        }
        return currSum+sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
    }
        
    
};