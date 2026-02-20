# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        ptr = ListNode(0)
        curr, c = ptr, 0
        while l1 or l2 or c:
            s = c
            if l1: s += l1.val; l1 = l1.next
            if l2: s += l2.val; l2 = l2.next

            c = s // 10
            curr.next = ListNode(s % 10)
            curr = curr.next

        return ptr.next