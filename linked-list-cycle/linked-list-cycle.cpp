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
    bool hasCycle(ListNode *head) {
        // unordered_set<ListNode*> visited;
        // while(head != NULL){
        //     if(visited.find(head) != visited.end())
        //         return true;
        //     visited.insert(head);
        //     head = head->next;
        // }
        // return false;


        ListNode *f=head, *s=head;
        while(f && s && f->next){
            f=f->next->next;
            s=s->next;
            if(f==s)
                return true;
        }
        return false;




        ListNode *fastPointer=head, *slowPointer=head;
        while(slowPointer && fastPointer && fastPointer->next){
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
            if(slowPointer == fastPointer)
                return true;
        }
        return false;
    }
};