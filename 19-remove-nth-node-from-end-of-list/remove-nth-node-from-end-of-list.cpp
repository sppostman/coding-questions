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
    // 1 2 3 4 5 6 7 8 9    n=3
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        while(n--){
            curr = curr->next;
        }
        if(curr == nullptr)
            return head->next;

        ListNode* remover = head;
        while(curr && curr->next){
            curr = curr->next;
            remover = remover->next;
        }
        ListNode *removedNode = remover->next;
        remover->next = remover->next ? remover->next->next : nullptr;
        delete removedNode;
        return head;
    }
};