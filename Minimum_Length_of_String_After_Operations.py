# 3223. Minimum Length of String After Operations
# Python3 Solution! problem-3223
class Solution:
    def minimumLength(self, s: str) -> int:
        cnt = [0 for _ in range(26)]
        for i in s:
            ind = ord(i)-97
            cnt[ind] += 1
        res = 0
        for i in cnt:
            if i != 0 and i % 2 == 0:
                res += 2
            elif i != 0 and i & 1:
                res += 1
        return res
