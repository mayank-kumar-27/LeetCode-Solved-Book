# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        def merge_two_list(l1, l2):
            if not l1:
                return l2
            if not l2:
                return l1
            
            if l1.val < l2.val:
                l1.next = merge_two_list(l1.next, l2)
                return l1
            else:
                l2.next = merge_two_list(l1, l2.next)
                return l2
        
        def d_and_c(left, right):
            if left == right:
                return lists[left]
            
            mid = left + (right - left) // 2
            l1 = d_and_c(left, mid)
            l2 = d_and_c(mid + 1, right)
            return merge_two_list(l1, l2)
        
        if not lists:
            return None
        return d_and_c(0, len(lists) - 1)
