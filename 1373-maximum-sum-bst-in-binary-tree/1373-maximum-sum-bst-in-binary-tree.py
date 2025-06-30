# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxSumBST(self, root: Optional[TreeNode]) -> int:
        self.maxSum = 0

        def dfs(node):
            if not node:
                return (True, float('inf'), float('-inf'), 0)

            leftIsBST, leftMin, leftMax, leftSum = dfs(node.left)
            rightIsBST, rightMin, rightMax, rightSum = dfs(node.right)

            if leftIsBST and rightIsBST and leftMax < node.val < rightMin:
                currentSum = node.val + leftSum + rightSum
                self.maxSum = max(self.maxSum, currentSum)
                return (True, min(leftMin, node.val), max(rightMax, node.val), currentSum)
            else:
                return (False, 0, 0, 0)

        dfs(root)
        return self.maxSum

        