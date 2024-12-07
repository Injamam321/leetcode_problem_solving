# Add Two Numbers
# Python3 Solution! problem-02
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        dummy = ListNode(0)
        current = dummy
        carry = 0  

        while l1 or l2 or carry:
           
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            
            total = val1 + val2 + carry
            carry = total // 10  
            new_digit = total % 10  
            
            current.next = ListNode(new_digit)
            current = current.next

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        return dummy.next
