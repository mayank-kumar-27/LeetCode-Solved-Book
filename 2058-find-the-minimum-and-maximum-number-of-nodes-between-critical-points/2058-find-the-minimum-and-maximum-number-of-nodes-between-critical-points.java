/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int[] r = { -1, -1 };
        int m = Integer.MAX_VALUE, ci = 1, pi = 0, fi = 0;
        ListNode p = head, c = head.next;
        while (c.next != null) {
            if ((c.val < p.val && c.val < c.next.val) || (c.val > p.val && c.val > c.next.val)) {
                if (pi == 0) { pi = ci; fi = ci; }
                else { m = Math.min(m, ci - pi); pi = ci; }
            }
            ci++; p = c; c = c.next;
        }
        if (m != Integer.MAX_VALUE) {
            int maxDistance = pi - fi;
            r = new int[] { m, maxDistance };
        } return r;
    }
}