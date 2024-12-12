# 7. Reverse Integer
# Python3 Solution! problem-7

class Solution:
    def reverse(self, x: int) -> int:
        # Determine if x is negative
        is_negative = x < 0
        if is_negative:
            x = -x  # Make x positive
        
        # Reverse the integer
        reversed_x = int(str(x)[::-1])
        
        # Check if reversed integer is within 32-bit range
        if reversed_x < -2**31 or reversed_x > 2**31 - 1:
            return 0
        
        # Return the result with the original sign
        return -reversed_x if is_negative else reversed_x
    