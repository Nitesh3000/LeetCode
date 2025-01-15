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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0){
            return nullptr;
        }
        return build(nums, 0, nums.size()-1);
    }
    TreeNode* build(vector<int>& nums, int start, int end){
        if(start>end)
            return nullptr;
        int maxIdx = start;
        for(int i = start;i<=end;i++){
            if(nums[i]>nums[maxIdx]){
                maxIdx = i;
            }
        }

        TreeNode* temp = new TreeNode(nums[maxIdx]);

        temp->left = build(nums,start,maxIdx-1);
        temp->right = build(nums,maxIdx+1,end);

        return temp;
    }
};