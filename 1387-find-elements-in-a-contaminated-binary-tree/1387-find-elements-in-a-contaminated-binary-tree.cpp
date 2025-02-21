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
class FindElements {
    
private:
    void FindEl(TreeNode* root){
        if(root == nullptr){
            return;
        }
        if(root->left){
            root->left->val = 2 * root->val + 1;
            FindEl(root->left);
        }
        if(root->right){
            root->right->val = 2* root->val + 2;
            FindEl(root->right);
        }
    }
public:
    TreeNode* root;
    FindElements(TreeNode* root) {
        root->val = 0;
        FindEl(root);
        this->root = root;
    }
    
    bool find(int target) {
        if(target == 0){
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node->left){
                if(node->left->val == target){
                    return true;
                }
                q.push(node->left);
            }
            if(node->right){
                if(node->right->val == target){
                    return true;
                }
                q.push(node->right);
            }
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */