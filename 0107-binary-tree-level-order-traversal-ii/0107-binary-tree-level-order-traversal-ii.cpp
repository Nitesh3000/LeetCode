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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr){
            return res ;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> temp;
        int numCurrent = 1;
        int numChild = 0;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            numCurrent--;
            temp.push_back(node->val);
            if(node->left!=nullptr){
                q.push(node->left);
                numChild++;
            }
            if(node->right!=nullptr){
                q.push(node->right);
                numChild++;
            }
            if(numCurrent == 0){
                numCurrent = numChild;
                numChild = 0;
                res.insert(res.begin(),temp);
                temp.clear();
            }
        }
        return res;
    }
};