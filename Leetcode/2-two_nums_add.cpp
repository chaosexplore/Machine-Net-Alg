/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int in = 0, tmp = 0;
        ListNode* ret = new ListNode(0);
        ListNode* head = ret;
        while (l1 || l2) {
            tmp = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + in;
            ret->val = tmp % 10;
 
            in = tmp > 9 ? 1 : 0;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;

            if(l1 || l2 || in) {
                ret->next = new ListNode(in);
                ret = ret->next; 
            }
        }

        return head;
    }
};