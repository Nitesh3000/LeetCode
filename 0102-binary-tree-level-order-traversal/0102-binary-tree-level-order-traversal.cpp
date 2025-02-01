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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        int currLevel = 1;
        int nextLevel = 0;
        queue<TreeNode*> q;
        vector<int> temp;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            currLevel--;
            temp.push_back(node->val);
            if(node->left != nullptr){
                q.push(node->left);
                nextLevel++;
            }
            if(node->right != nullptr){
                q.push(node->right);
                nextLevel++;
            }
            if(currLevel == 0){
                res.push_back(temp);
                temp.clear();
                currLevel = nextLevel;
                nextLevel = 0;
            }
        }
        return res;
    }
};