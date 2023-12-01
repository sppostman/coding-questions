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
    ListNode* rev(ListNode* head, ListNode* prev) {
        if(!head)
            return NULL;
        ListNode *newHead = head->next ? rev(head->next, head) : head;
        head->next = prev;
        return newHead;
    }
    ListNode* reverseList(ListNode* head) {
        // Rec without prev
        if(!head || !head->next)
            return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;

        // Rec with prev
        // return rev(head, NULL);

        // ListNode *prev = NULL;
        // ListNode *nxt = NULL;
        // while(head){
        //     nxt = head->next;
        //     head->next = prev;
        //     prev = head;
        //     head = nxt;
        // }
        // return prev;
    }
};