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
    TreeNode* recoverFromPreorder(string traversal) {
        map<int,TreeNode*> tree_map;
        int num = 0;
        int j = 0;
        while (j < traversal.size() && isdigit(traversal[j])) {
                num = num * 10 + (traversal[j] - '0');
                j++;
        }
        
        TreeNode* root =new TreeNode(num);
        tree_map[0] = root;
        for(int i=j;i<traversal.size();i++){
            int count = 0;
            while(traversal[i] == '-'){
                i++;
                count++;
            }
            num = 0;
            while (i < traversal.size() && isdigit(traversal[i])) {
                num = num * 10 + (traversal[i] - '0');
                i++;
            }
            i--;
            TreeNode* temp =new TreeNode(num);
            if(tree_map.find(count) == tree_map.end()){
                tree_map[count-1]->left = temp;
                tree_map[count] = temp;
            }
            else{
                tree_map[count-1]->right = temp;
                tree_map[count] = temp;
                count++;
                while(tree_map.find(count)!=tree_map.end()){
                    tree_map.erase(count);
                    count++;
                }
            }
        }
        return root;
    }
};