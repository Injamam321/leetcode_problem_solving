# 2054. Two Best Non-Overlapping Events
# Python3 Solution!

from bisect import bisect_left

class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
       
        events.sort(key=lambda x: x[1])
        max_value = 0  
        result = 0     
        dp = [] 

        for start, end, value in events:
            idx = bisect_left(dp, (start,))
            max_non_overlap = dp[idx - 1][1] if idx > 0 else 0
            
            result = max(result, value + max_non_overlap)
            
            max_value = max(max_value, value)
            dp.append((end, max_value))
    
        return result
