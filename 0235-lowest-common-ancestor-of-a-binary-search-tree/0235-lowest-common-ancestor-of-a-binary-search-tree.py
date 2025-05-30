# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def traverse(node):

            if p.val > node.val and q.val > node.val:
                return traverse(node.right)
            elif p.val < node.val and q.val < node.val:
                return traverse(node.left)
            else:
                return node

            # if p.val <= node.val and node.val <= q.val:
            #     return node 

            # elif p.val > node.val:
            #     r = traverse(node.right)
            # else:
            #     r = traverse(node.left)

            # if r != -1:
            #     return r

            # return None

        return traverse(root)