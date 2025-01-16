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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i; 
        }

        int preorder_index = 0; // Pointer to track current root in preorder
        int inorder_start = 0;
        return build(preorder, inorder, preorder_index, inorder_start, inorder.size() - 1, inorder_map);
    }

private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preorder_index, 
                    int inorder_start, int inorder_end, unordered_map<int, int>& inorder_map) {        
        if (inorder_start > inorder_end) return nullptr;
        
        int root_val = preorder[preorder_index++];
        TreeNode* root = new TreeNode(root_val);

        int inorder_index = inorder_map[root_val];

        root->left = build(preorder, inorder, preorder_index, inorder_start, inorder_index - 1, inorder_map);
        root->right = build(preorder, inorder, preorder_index, inorder_index + 1, inorder_end, inorder_map);

        return root;
    }
};