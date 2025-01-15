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
        if(root==nullptr){
            return root;
        }
        queue<Node*> q;
       
        int nextLevel = 0, currentLevel = 1;
        q.push(root);
        Node* prevNode = nullptr;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            currentLevel--;

            if(temp->left!=nullptr){
                q.push(temp->left);
                nextLevel++;
                if(prevNode){
                    prevNode->next = temp->left;
                     
                }
                prevNode = temp->left;
                // temp->left->next = temp->right;

            }
            if(temp->right!=nullptr){
                q.push(temp->right);
                nextLevel++;
                if(prevNode){
                    prevNode->next = temp->right;
                     
                }
                prevNode = temp->right;
            }
            
            if(currentLevel == 0){
                currentLevel = nextLevel;
                nextLevel = 0;
                prevNode = nullptr;
            }

        }
        
        return root;
    }
};