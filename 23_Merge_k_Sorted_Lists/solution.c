/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    
    if (l1->val < l2->val) { l1->next = merge(l1->next, l2); return l1; } 
    else { l2->next = merge(l1, l2->next); return l2; }
}

struct ListNode* d_and_c(struct ListNode** lists, int left, int right) {
    if (left == right) return lists[left];
    
    int mid = left + (right - left) / 2;
    struct ListNode* l1 = d_and_c(lists, left, mid);
    struct ListNode* l2 = d_and_c(lists, mid + 1, right);
    return merge(l1, l2);
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    return d_and_c(lists, 0, listsSize - 1);
}
