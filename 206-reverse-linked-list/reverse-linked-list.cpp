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
    ListNode* reverseList(ListNode* head) {

        ListNode *curr = head;
        ListNode *prev=NULL, *newer=NULL;
        while(curr){
            newer = curr->next;
            curr->next=prev;
            prev=curr;
            curr = newer;
        }
        return prev;




        // ListNode *newer = NULL;
        // ListNode *curr = head;

        // ListNode *nxt;
        // while(curr){
        //     nxt = curr->next;
        //     curr->next = newer;
        //     newer = curr;
        //     curr = nxt;
        // }

        return newer;
    }
};