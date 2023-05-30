/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        while(n-- > 0){
            curr = curr->next;
        }

        ListNode* remover=head;
        while(curr && curr->next){
            remover = remover->next;
            curr = curr->next;
        }
        if(remover == head && curr == NULL)
            return head->next;
        remover->next = remover->next ? remover->next->next : NULL;
        return head;
    }




    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        ListNode* curr = head;
        while(n-- > 0)
            curr = curr -> next;
        ListNode* target = head;
        while(curr != NULL && curr->next != NULL){
            curr = curr -> next;
            target = target -> next;
        }
        // if(target)
        //     cout << "Target: " << target->val;
        // if(curr)
        //     cout << ", curr: " << curr->val;
        cout << endl;
        if(target == NULL)
            return NULL;
        if(target == head && curr == NULL)
            return target->next;
        target -> next = target -> next -> next;
        return head;
    }
    
};