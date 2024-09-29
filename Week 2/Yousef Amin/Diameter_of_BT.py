# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSubtree(self, root, subRoot):
        """
        :type root: TreeNode
        :type subRoot: TreeNode
        :rtype: bool
        """
        def helper(root):
            if not root:
                return False
            if self.same_tree(root, subRoot):
                return True
            helper(self.left)
            helper(self.right)
        
    def same_tree(self,first,second):
        if not first and not second:
            return True
        elif not first or not second:
            return False
        return first.val == second.val and self.same_tree(first.left,second.left) and self.same_tree(first.right,second.right)