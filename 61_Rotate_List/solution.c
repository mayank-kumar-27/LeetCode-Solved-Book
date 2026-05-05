struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;
    int l = 1;
    struct ListNode* t = head;
    while (t->next) {
        t = t->next;
        l++;
    }
    k %= l;
    if (k == 0) return head;

    t->next = head;
    int s = l - k;
    struct ListNode* nt = head;
    for (int i = 1; i < s; i++) nt = nt->next;

    struct ListNode* nh = nt->next;
    nt->next = NULL;
    return nh;
}
