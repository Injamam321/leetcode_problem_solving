# 3152. Special Array II
# Python3 Solution! problem-3152

class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        n = len(nums)
        invalid = [0] * n  
        
        for i in range(n - 1):
            if nums[i] % 2 == nums[i + 1] % 2:  
                invalid[i] = 1

        prefix = [0] * n
        for i in range(1, n):
            prefix[i] = prefix[i - 1] + invalid[i - 1]

        result = []
        for fromi, toi in queries:
            if prefix[toi] - prefix[fromi] == 0:
                result.append(True)
            else:
                result.append(False)
        
        return result
