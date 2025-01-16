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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
         if(root == nullptr){
            return res;
        }
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        vector<int> reslevel;
        int level = 0 , currlevel = 1, nextlevel = 0;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            currlevel--;
            if(level%2 == 0){
                reslevel.push_back(temp->val);
            }
            else{
                s.push(temp);
            }
            if(temp->left){
                q.push(temp->left);
                nextlevel++;
            }
            if(temp->right){
                q.push(temp->right);
                nextlevel++;
            }
            if(currlevel == 0){
                currlevel = nextlevel;
                nextlevel = 0;
                if(level%2 != 0){
                    while(!s.empty()){
                        reslevel.push_back((s.top())->val);
                        s.pop();
                    }
                }
                res.push_back(reslevel);
                reslevel.clear();
                level++;
            }
           
        } 
         return res;
    }
};