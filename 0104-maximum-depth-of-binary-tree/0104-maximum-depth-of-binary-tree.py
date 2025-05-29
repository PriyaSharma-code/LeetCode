# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        queue = [(root,1)]
        self.res =0

        while queue:
            root,num = queue.pop(0)
            if not root.left and not root.right:
                self.res = max(self.res,num)
            if root.left:
                queue.append((root.left,num+1))
            if root.right:
                queue.append((root.right,num+1))
        return self.res