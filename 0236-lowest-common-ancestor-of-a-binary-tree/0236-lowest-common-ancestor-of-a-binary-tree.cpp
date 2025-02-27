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
        
        if(root == nullptr || p == root || q == root){
            return root;
        }
        TreeNode* leftSubtree = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightSubtree = lowestCommonAncestor(root->right,p,q);
        if(leftSubtree!=nullptr && rightSubtree==nullptr){
            return leftSubtree;
        }
        if(leftSubtree==nullptr && rightSubtree!=nullptr){
            return rightSubtree;
        }
        if(leftSubtree!=nullptr && rightSubtree!=nullptr){
            return root;
        }
        else{
            return nullptr;
        }
       
        
    }
};