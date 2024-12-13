# 8. String to Integer (atoi)
# Python3 Solution! problem-8

class Solution(object):
    def myAtoi(self, s):
        s = s.strip()  # Remove leading and trailing whitespace
        if not s:
            return 0  # Handle empty string case
        num = 0
        i = 0
        sign = 1  # 1 for positive, -1 for negative
        if s[i] == '+':
            i += 1
        elif s[i] == '-':
            i += 1
            sign = -1
        while i < len(s) and s[i].isdigit():
            num = num * 10 + int(s[i])
            i += 1
        num *= sign
        num = max(min(num, 2 ** 31 - 1), -2 ** 31)  # Check for integer overflow
        return num