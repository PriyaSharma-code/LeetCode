# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []
        retList = []
        queue = deque()
        queue.append(root)
        while queue:
            length = len(queue)
            for i in range(0, length):
                node = queue.popleft()
                if (i == length-1):
                    retList.append(node.val)
                if (node.left):
                    queue.append(node.left)
                if (node.right):
                    queue.append(node.right)
        return retList



