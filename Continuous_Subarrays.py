# 2762. Continuous Subarrays
#  Python3 Solution! problem-2762

from typing import List
from collections import deque

class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        left = 0
        result = 0

        # Deques to maintain the maximum and minimum values in the window
        max_deque = deque()
        min_deque = deque()

        for right in range(n):
            # Maintain max_deque
            while max_deque and nums[max_deque[-1]] < nums[right]:
                max_deque.pop()
            max_deque.append(right)

            # Maintain min_deque
            while min_deque and nums[min_deque[-1]] > nums[right]:
                min_deque.pop()
            min_deque.append(right)

            # Ensure the window is valid
            while nums[max_deque[0]] - nums[min_deque[0]] > 2:
                left += 1
                # Remove indices outside the current window
                if max_deque[0] < left:
                    max_deque.popleft()
                if min_deque[0] < left:
                    min_deque.popleft()

            # Count subarrays ending at `right`
            result += (right - left + 1)

        return result
