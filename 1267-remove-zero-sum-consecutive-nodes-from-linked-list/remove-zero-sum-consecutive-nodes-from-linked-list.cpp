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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int, ListNode*> presummed;

        ListNode *dhead = new ListNode(-1, head);
        presummed[0] = dhead;

        int sum = 0;
        ListNode* curr = head;
        while(curr != nullptr){
            sum += curr->val;

            // if(sum == 0){
            //     prev = dhead;
            //     dhead->next = curr->next;
            //     presummed.clear();
            // } else
            if(presummed[sum] != nullptr){
                ListNode *prevlink = presummed[sum];
                
                int tempsum = sum;
                ListNode *tmp = prevlink->next;
                while(tmp && tmp != curr){
                    tempsum += tmp->val;
                    presummed.erase(tempsum);
                    tmp = tmp->next;
                }

                prevlink->next = curr->next;
            } else {
                presummed[sum] = curr;
            }
            curr = curr->next;
        }
        
        // 1 2 -3 3 1
        // 1 3 0 3 4

        // 1 2 3 -3 4
        // 1 3 6 3 7

        // 1 2 3 -3 -2
        // 1 3 6 3 4

        // 2 2 -2 1 -1 -1
        // 2 4 2 3 2 1

        // 2 1 -1 -1
        // 2 3 2 1

        return dhead->next;
    }
};