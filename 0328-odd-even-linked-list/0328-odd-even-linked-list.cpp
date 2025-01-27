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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr){
            return head;
        }
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* dummy = second;
        int i = 0;
       
        ListNode* prev = first;
        while(first!=nullptr && second!=nullptr){
            prev = first;
            ListNode* temp = second;
            first->next = second->next;
            second = first->next;
            first = temp;
            i++;
        }
        if(i%2 == 0)
            first->next = dummy;
        else{
            prev->next = dummy;
        }
        return head;


    }
};