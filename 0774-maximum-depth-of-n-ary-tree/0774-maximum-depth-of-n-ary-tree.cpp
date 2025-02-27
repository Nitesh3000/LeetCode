/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    int maxDepth(Node* root, int height){
        if(root == nullptr){
            return 0;
        }
        int currHeight = height;
        for(Node* child:root->children){
            height = max(height,maxDepth(child,currHeight));
        }
        return 1+height;
    }
public:
    int maxDepth(Node* root) {
        if(root == nullptr){
            return 0;
        }
        int height = 0;
        height = maxDepth(root,height);
        return height;
    }
};