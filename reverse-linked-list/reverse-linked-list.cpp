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

        ListNode *newer = NULL, *curr = head;
        ListNode *tmp;
        while(curr){
            tmp = curr->next;
            curr->next = newer;
            newer = curr;
            curr = tmp;
        }
        return newer;





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