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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(root==nullptr) return res;

        vector<int> resPath;
        stack<pair<vector<int>,pair<TreeNode*,int>>> st;
        st.push({{root->val},{root,root->val}});
        while(!st.empty()){
            TreeNode* node = st.top().second.first;
            vector<int> path = st.top().first;
            int currentSum = st.top().second.second;
            st.pop();
            // currentSum+=node->val;
            // path.push_back(node->val);
            if(node->left==nullptr && node->right == nullptr && currentSum == targetSum){
                
                res.push_back(path);
            }
            if(node->left!=nullptr){
                vector<int> tempPath = path;
                tempPath.push_back(node->left->val);
                st.push({tempPath,{node->left,currentSum+node->left->val}});
            }
            if(node->right!=nullptr){
                vector<int> tempPath = path;
                tempPath.push_back(node->right->val);
                st.push({tempPath,{node->right,currentSum+node->right->val}});
            }

        }
        return res;
    }
};