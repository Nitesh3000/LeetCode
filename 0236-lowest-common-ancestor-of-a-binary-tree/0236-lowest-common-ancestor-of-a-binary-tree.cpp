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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || root == nullptr){
            return root;
        }
        TreeNode* l = lowestCommonAncestor(root->left, p,q);
        TreeNode* r = lowestCommonAncestor(root->right, p,q);
        if(l == nullptr && r == nullptr){
            return nullptr;
        }
        if(l == nullptr){
            return r;
        }
        else if(r == nullptr){
            return l;
        }
        else{
            return root;
        }
    }
};