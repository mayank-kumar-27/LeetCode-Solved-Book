# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next or k == 0:
            return head

        l = 1
        t = head
        while t.next:
            t = t.next
            l += 1

        k %= l
        if k == 0:
            return head

        t.next = head

        s = l - k
        nt = head
        for _ in range(1, s):
            nt = nt.next

        nh = nt.next
        nt.next = None

        return nh
