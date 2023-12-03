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
        ListNode *result = new ListNode(-1);
        ListNode *l3 = result;
        int carry = 0;

        while(l1 || l2){
            int sum = carry;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            l3->next = new ListNode(sum % 10);
            carry = sum / 10;
            l3 = l3->next;
        }
        
        if(carry){
            l3->next = new ListNode(carry);
        }
        return result->next;

        // ListNode *result = new ListNode(-1);
        // ListNode *l3 = result;
        // int carry = 0;

        // while(l1 && l2){
        //     l3->next = new ListNode((l1->val+l2->val+carry) % 10);
        //     carry = (l1->val+l2->val+carry) / 10;
        //     l1 = l1->next;
        //     l2 = l2->next;
        //     l3 = l3->next;
        // }

        // while(l1){
        //     l3->next = new ListNode((l1->val+carry) % 10);
        //     carry = (l1->val+carry) / 10;
        //     l1 = l1->next;
        //     l3 = l3->next;
        // }
        // while(l2){
        //     l3->next = new ListNode((l2->val+carry) % 10);
        //     carry = (l2->val+carry) / 10;
        //     l2 = l2->next;
        //     l3 = l3->next;
        // }
        // if(carry){
        //     l3->next = new ListNode(carry);
        // }
        // return result->next;
    }
};