# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque, defaultdict
from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        # Step 1: Build an undirected graph (as adjacency list)
        graph = defaultdict(list)
        
        def build_graph(node, parent):
            if not node:
                return
            if parent:
                graph[node].append(parent)
                graph[parent].append(node)
            build_graph(node.left, node)
            build_graph(node.right, node)
        
        build_graph(root, None)

        # Step 2: BFS from the target node
        visited = set()
        queue = deque([(target, 0)])
        result = []

        while queue:
            node, dist = queue.popleft()
            if node in visited:
                continue
            visited.add(node)
            if dist == k:
                result.append(node.val)
            elif dist < k:
                for neighbor in graph[node]:
                    if neighbor not in visited:
                        queue.append((neighbor, dist + 1))
        
        return result

        