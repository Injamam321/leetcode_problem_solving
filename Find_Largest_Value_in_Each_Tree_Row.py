# 515.Find Largest Value in Each Tree Row
# Python3 Solution! problem-515

from collections import deque
from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        
        result = []
        queue = deque([root])  # BFS Queue
        
        while queue:
            level_size = len(queue)
            max_value = float('-inf')  # Initialize max for the level
            
            for _ in range(level_size):
                node = queue.popleft()
                max_value = max(max_value, node.val)  # Update max_value
                
                # Add child nodes to the queue
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            result.append(max_value)  # Add max of the current level to result
        
        return result