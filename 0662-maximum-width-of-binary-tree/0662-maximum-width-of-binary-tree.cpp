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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int width = 0;
        queue<pair<TreeNode*,long>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            
            long min=q.front().second;
            long start , end ;
            for(int i = 0;i<size;i++){
                long currIndx = q.front().second - min;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0) start = currIndx;
                if(i == size - 1) end = currIndx;

                if(node->left!=nullptr) q.push({node->left, 2*currIndx+1});
                if(node->right!=nullptr) q.push({node->right, 2*currIndx+2});
            }
            width = max(width,static_cast<int>(end-start+1));
        }
        return width;
    }
};