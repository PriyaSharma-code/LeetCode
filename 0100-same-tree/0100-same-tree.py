# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        def same(p, q): 
            if p is None: 
                if q is not None: 
                    return False
                return True
            else: 
                if q is None: 
                    return False
                if p.val == q.val: 
                    return same(p.left, q.left) and same(p.right, q.right)
                else:
                     return False
        return same(p, q)