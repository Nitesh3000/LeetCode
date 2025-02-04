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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        int currLevel = 1, nextLevel = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            currLevel--;
            if(node->left != nullptr){
                q.push(node->left);
                nextLevel++;
            }
            if(node->right != nullptr){
                q.push(node->right);
                nextLevel++;
            }
            if(currLevel == 0){
                res.push_back(node->val);
                currLevel = nextLevel;
                nextLevel = 0;
            }
            
        }
        return res;
    }
};