"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return None

        leftmost = root
        while leftmost.left:
            head = leftmost
            while head:
                # Connect left child to right child
                head.left.next = head.right
                # Connect right child to the next subtree's left child
                if head.next:
                    head.right.next = head.next.left
                head = head.next
            leftmost = leftmost.left

        return root
        