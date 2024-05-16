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
    pair<ListNode*, int> doubleUtil(ListNode* head){
        if(head == nullptr)
            return {nullptr, 0};
        
        auto result = doubleUtil(head->next);

        int carry = (head->val * 2 + result.second) / 10.0;
        head->val = (head->val * 2 + result.second) % 10;

        return {head, carry};
    }
    ListNode* doubleIt(ListNode* head) {
        auto result = doubleUtil(head);
        if(result.second == 0)
            return head;
        return new ListNode(result.second, head);
    }
};