# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        
        res = [True]
        def helper(root):
            if not root:
                return
            left = helper(root.left)
            right = helper(root.right)
            if abs(left-right)>1:
                res[0] = False
            return 1+max(left,right)
        helper(root)
        return res[0]