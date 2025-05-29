# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        dummy = node = TreeNode()
        q = deque()
        if root is None:
            return []
        if root.left is None and root.right is None:
            return [root.val]

        q.append(root)
        view=[]

        while q:
            child_q =deque()
            prev = -1
            while q:
                curr = q.popleft()
                if curr.left is not None:
                    child_q.append(curr.left)
                if curr.right is not None:
                    child_q.append(curr.right)
                prev = curr
            view.append(prev.val)
            q=child_q
        return view

