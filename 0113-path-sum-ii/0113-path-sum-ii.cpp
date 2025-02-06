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
        if(root == nullptr){
            return res;
        }
        stack<pair<TreeNode*,pair<vector<int>,int>>> st;
        vector<int> currPath = {root->val};
        st.push({root,{{},0}});
        while(!st.empty()){
            auto temp = st.top();
            auto node = temp.first;
            auto path = temp.second.first;
            auto sum = temp.second.second;
            st.pop();
            path.push_back(node->val);
            if(node->val + sum == targetSum){
                if(node->left == nullptr && node->right == nullptr){
                    res.push_back(path);
                }
            }
            if(node->right != nullptr){
                st.push({node->right,{path,sum+node->val}});
            }
            if(node->left != nullptr){
                st.push({node->left,{path,sum+node->val}});
            }
        }
        return res;
    }
};