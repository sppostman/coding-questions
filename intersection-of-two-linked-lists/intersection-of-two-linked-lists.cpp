/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Optimal
        ListNode *t1 = headA, *t2 = headB;
        while(t1 != t2){
            t1 = t1 ? t1->next : headB;
            t2 = t2 ? t2->next : headA;
        }
        return t1;



        // Better
        ListNode *x=headA, *y=headB;
        int m=0,n=0;
        while(x && y){
            m++;
            x = x->next;
            y = y->next;
        }
        n=m;
        while(x){
            m++;
            x=x->next;
        }
        while(y){
            n++;
            y=y->next;
        }
        int diff = abs(m-n);
        ListNode* longer = m>=n ? headA : headB;
        ListNode* stn = m>=n ? headB : headA;
        // printf("Diff %d, longer %d, stn %d, (m,n) => (%d,%d)\n", diff,longer->val,stn->val,m,n);
        while(diff-->0 && longer){
            longer = longer->next;
        }
        while(longer && stn){
            if(longer==stn)
                return stn;
            stn = stn->next;
            longer = longer->next;
        }

        return NULL;
    }
};