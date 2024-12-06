# Approach 1: Brute Force
# Python3 Solution!


class Solution:
    def twoSum(self, nums, target):
        seen = {}  
        
        for index, num in enumerate(nums):
            complement = target - num  
            
            if complement in seen:  
                return [seen[complement], index]
            
            seen[num] = index  
