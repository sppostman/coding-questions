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
    void reorderList(ListNode* head) {
        ListNode* curr=head;
        stack<ListNode*> rev;
        int totalSize = 0;
        while(curr){
            rev.push(curr);
            curr= curr->next;
            totalSize++;
        }
        // printf("Size %d\n", totalSize);

        int len = 0;
        curr = head;
        ListNode* next;
        for(int i=0; i<totalSize/2; i++){
            next = curr->next;
            rev.top()->next = curr->next;
            curr->next = rev.top();
            rev.pop();
            len+=2;
            curr = next;
        }
        curr->next =nullptr;
    }
};