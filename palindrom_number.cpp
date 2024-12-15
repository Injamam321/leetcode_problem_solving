// 9. palindrome number
// cpp Solution! problem-9


class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) 
            return false;
        
        // Reverse the second half of the number
        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;  // Append the last digit
            x /= 10;  // Remove the last digit from x
        }
        
        // Compare the original half and reversed half
        return (x == reversedHalf || x == reversedHalf / 10); // Handles odd-length cases
    }
};
