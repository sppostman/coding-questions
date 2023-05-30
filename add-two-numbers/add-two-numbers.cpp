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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int tmp = l1->val+l2->val;
        ListNode *result = new ListNode(tmp%10);
        ListNode *resHead = result;
        int carry = tmp >= 10 ? 1 : 0;
        l1 = l1->next;
        l2 = l2->next;
        // printf("sum %d, carry %d\n",tmp,carry);

        while(l1 && l2){
            tmp = l1->val+l2->val +carry;
            result->next = new ListNode(tmp%10);
            carry = tmp >= 10 ? 1 : 0;
            result=result->next;
            l1 = l1->next;
            l2 = l2->next;
            // printf("sum %d, carry %d\n",tmp,carry);
        }
        while(l1){
            tmp = l1->val+carry;
            result->next = new ListNode(tmp%10);
            carry = tmp >= 10 ? 1 : 0;
            result=result->next;
            l1 = l1->next;
            // printf("carry %d\n",carry);
        }
        while(l2){
            tmp = l2->val +carry;
            result->next = new ListNode(tmp%10);
            carry = tmp >= 10 ? 1 : 0;
            result=result->next;
            l2 = l2->next;
            // printf("carry %d\n",carry);
        }
        if(carry){
            result->next = new ListNode(carry);
        }
        return resHead;
    }
};