# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, h: Optional[ListNode]) -> Optional[ListNode]:
        if not h or not h.next:
            return None
        s = h
        f = h.next.next
        while f and f.next:
            s = s.next
            f = f.next.next
        s.next = s.next.next
        return h