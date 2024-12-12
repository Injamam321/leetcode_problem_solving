# 2558. Take Gifts From the Richest Pile
# # Python3 Solution! problem-2558
import heapq
import math
from typing import List

class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        # Use a max-heap by pushing negative values (Python has a min-heap by default)
        max_heap = [-gift for gift in gifts]
        heapq.heapify(max_heap)  # Convert the list into a heap
        
        # Perform the operation `k` times
        for _ in range(k):
            # Extract the pile with the maximum gifts
            max_gifts = -heapq.heappop(max_heap)
            # Calculate the remaining gifts in the pile after taking the gifts
            remaining_gifts = math.floor(math.sqrt(max_gifts))
            # Push the remaining gifts back into the heap
            heapq.heappush(max_heap, -remaining_gifts)
        
        # Calculate the total number of gifts remaining
        total_gifts = -sum(max_heap)
        return total_gifts

# time complexity : O(k log n)
# space complexity: O(n)
