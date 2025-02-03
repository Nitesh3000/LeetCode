/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr){
            return root;
        }
        queue<Node*> q;
        int currLevel = 1;
        int nextLevel = 0;
        q.push(root);
        Node* prev = nullptr;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            currLevel--;
            if(prev!=nullptr){
                prev->next = node;
            }
            prev = node;
            if(node->left != nullptr){
                q.push(node->left);
                nextLevel++;
            }
            if(node->right!=nullptr){
                q.push(node->right);
                nextLevel++;
            }
            if(currLevel == 0){
                node->next = nullptr;
                prev = nullptr;
                currLevel = nextLevel;
                nextLevel = 0;
            }
        }
        return root;
    }
};