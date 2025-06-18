# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        nodes = []
# brute force
        def dfs(node, x, y):
            if not node:
                return
            nodes.append((x, y, node.val))
            dfs(node.left, x - 1, y + 1)
            dfs(node.right, x + 1, y + 1)

        dfs(root, 0, 0)

        nodes.sort()  # sorts by x, then y, then value

        res = []
        prev_x = float('-inf')
        for x, y, val in nodes:
            if x != prev_x:
                res.append([])
                prev_x = x
            res[-1].append(val)

        return res