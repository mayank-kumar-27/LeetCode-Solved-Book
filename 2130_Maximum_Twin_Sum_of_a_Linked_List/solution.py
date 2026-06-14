# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        s = f = head
        while f and f.next:
            s = s.next
            f = f.next.next
        p = None
        while s:
            n = s.next
            s.next = p
            p = s
            s = n
        a = head
        r = 0
        while p:
            r = max(r, a.val + p.val)
            a = a.next
            p = p.next
        return r
