/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head) {
    struct ListNode *s=head,*f=head,*p=NULL,*n,*a;
    while(f&&f->next){
        s=s->next;
        f=f->next->next;
    }
    while(s){
        n=s->next;
        s->next=p;
        p=s;
        s=n;
    }
    int r=0,t;
    a=head;
    while(p){
        t=a->val+p->val;
        if(t>r) r=t;
        a=a->next;
        p=p->next;
    }
    return r;
}