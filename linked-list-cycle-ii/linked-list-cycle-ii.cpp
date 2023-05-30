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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        ListNode *f=head, *s=head;
        while(f && s && f->next){
            f=f->next->next;
            s=s->next;
            if(f==s)
                break;
        }
        if(f!=s)    
            return NULL;
        s=head;
        while(s!=f){
            s=s->next;
            f=f->next;
        }
        return s;
    }
};