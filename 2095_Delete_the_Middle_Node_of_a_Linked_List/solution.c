/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* h) {
    if (!h || !h->next) return NULL;
    struct ListNode *s = h, *f = h->next->next;
    while (f && f->next) {
        s = s->next;
        f = f->next->next;
    }
    s->next = s->next->next;
    return h;
}