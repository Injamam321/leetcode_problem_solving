# 6. Zigzag Conversion
# Python3 Solution! problem-06

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:  # If there's only one row, no zigzag pattern is possible; return the string as is
            return s

        rows = [""] * numRows # Create a list to hold strings for each row

        current_row = 0  # Variables to track the current row and the direction of traversal (up or down)
        going_down = False

        for char in s:    # Iterate through each character in the input string
            rows[current_row] += char  # Add the character to the current row
            
            if current_row == 0 or current_row == numRows - 1:  # Change direction if we're at the top or bottom row
                going_down = not going_down
            
            current_row += 1 if going_down else -1  # Update the current row based on the direction

        return "".join(rows)   # Join all the rows into a single string


# Time Complexity: O(n)
# Space Complexity: O(n)