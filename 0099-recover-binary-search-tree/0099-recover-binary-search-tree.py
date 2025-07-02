# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        # Initialize variables to keep track of the two nodes that need to be swapped
        self.first = self.second = self.prev = None

        def inorder(node):
            if not node:
                return

            # In-order traversal
            inorder(node.left)

            # Detect swapped nodes
            if self.prev and self.prev.val > node.val:
                if not self.first:
                    self.first = self.prev
                self.second = node

            self.prev = node

            inorder(node.right)

        inorder(root)

        # Swap the values of the two misplaced nodes
        if self.first and self.second:
            self.first.val, self.second.val = self.second.val, self.first.val

        