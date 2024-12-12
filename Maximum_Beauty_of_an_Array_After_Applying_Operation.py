# 2779. Maximum Beauty of an Array After Applying Operation
# Python3 Solution! problem-2779


class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        # Extend the range of each element to [nums[i] - k, nums[i] + k]
        ranges = [(num - k, num + k) for num in nums]

        # Sort the ranges by their start values, and then by end values
        ranges.sort()

        max_beauty = 0
        window_start = 0
        endpoints = []

        # Sliding window to find the maximum overlapping ranges
        for start, end in ranges:
            endpoints.append(end)

            # Remove ranges that no longer overlap with the current start
            while endpoints and endpoints[0] < start:
                endpoints.pop(0)
                window_start += 1

            # Update maximum beauty (number of overlapping ranges)
            max_beauty = max(max_beauty, len(endpoints))

        return max_beauty
    
    
    # time complexity is: O(n log n)
    #space complexity is: O(n)
