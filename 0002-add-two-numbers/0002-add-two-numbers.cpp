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

 /*
 [2,4,3]
 [5,6,4]
 [7,0,8]

 [9,9,9,9,9,9,9]
 [9,9,9,9]
 [8,9,9,9,0,0,0,1]
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int sum = l1->val + l2->val;
        int carry = sum/10;
        int rem = sum%10;
        ListNode* head = new ListNode(rem);
        ListNode* prev = head;
        l1 = l1->next;
        l2 = l2->next;
        while(l1!=nullptr || l2!=nullptr){
            if(l1!=nullptr && l2!=nullptr){
                sum = l1->val+l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1!=nullptr){
                    sum = l1->val+carry;
                    l1= l1->next;
                }
            else if(l2!=nullptr){
                sum = l2->val+carry;
                l2=l2->next;
            }
        
            rem = sum%10;
            ListNode* node = new ListNode(rem);
            prev->next = node;
            prev = node;
            carry = sum/10;
        }
        if(carry > 0){
            ListNode* node = new ListNode(carry);
            prev->next = node;
        }
        return head;
        
    }
};