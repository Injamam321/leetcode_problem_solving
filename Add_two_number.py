# Add Two Numbers
# Python3 Solution! problem-02

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # Dummy node to simplify list construction
        dummy = ListNode(0)
        current = dummy
        carry = 0  # Tracks carry from previous addition

        while l1 or l2 or carry:
            # Extract values from l1 and l2, or use 0 if null
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0

            # Calculate total for this digit
            total = val1 + val2 + carry
            carry = total // 10  # Compute carry
            new_digit = total % 10  # Compute digit to store

            # Append the new digit to the result list
            current.next = ListNode(new_digit)
            current = current.next

            # Move to the next nodes if available
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        # Return the head of the new list (skipping dummy node)
        return dummy.next
