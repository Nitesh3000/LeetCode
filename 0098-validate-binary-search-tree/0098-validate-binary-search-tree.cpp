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
private:
    bool isValid(TreeNode* root, TreeNode* minNode,TreeNode* maxNode){
        if(root == nullptr) return true;

        if((minNode && root->val <= minNode->val) || (maxNode && root->val>=maxNode->val)) return false;

        return isValid(root->left,minNode,root) && isValid(root->right,root,maxNode);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValid(root,nullptr,nullptr);
        
    }
};