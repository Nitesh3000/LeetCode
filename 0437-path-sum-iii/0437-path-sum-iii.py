# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def pathSumInclude(self,root,targetSum):
        if root == None:
            return 0
        res = 0
        if root.val == targetSum:
            res+=1
        res+=self.pathSumInclude(root.left,targetSum-root.val)
        res+=self.pathSumInclude(root.right,targetSum-root.val)
        return res
            
    def pathSum(self, root, targetSum):
        """
        :type root: Optional[TreeNode]
        :type targetSum: int
        :rtype: int
        """
        if root == None:
            return 0
        return self.pathSum(root.left,targetSum) + self.pathSum(root.right,targetSum) + self.pathSumInclude(root,targetSum)


        