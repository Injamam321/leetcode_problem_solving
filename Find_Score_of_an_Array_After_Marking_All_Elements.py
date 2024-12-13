# 2593. Find Score of an Array After Marking All Elements
# Python3 Solution! problem-2593

class Solution:
    def findScore(self, nums: List[int]) -> int:
        n = len(nums)
        # Pair each element with its index and sort by value first, then by index
        indexed_nums = sorted((value, idx) for idx, value in enumerate(nums))
        
        # Track marked elements
        marked = [False] * n
        score = 0

        # Process each element in sorted order
        for value, idx in indexed_nums:
            # If the current element is not already marked
            if not marked[idx]:
                # Add its value to the score
                score += value
                # Mark the current element and its neighbors if they exist
                marked[idx] = True
                if idx > 0:
                    marked[idx - 1] = True
                if idx < n - 1:
                    marked[idx + 1] = True
        
        return score
