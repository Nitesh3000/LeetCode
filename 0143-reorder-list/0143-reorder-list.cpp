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
        if(head == nullptr || head->next == nullptr){
            return;
        }
         //1. Find Middle
         ListNode* fast = head;
         ListNode* slow = head;
         while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
         }

         //2. Rerverse the second half
         ListNode* first = slow;
         ListNode* second = slow->next;
         while(second!=nullptr){
            ListNode* third = second->next;
            second->next = first;
            first = second;
            second = third;
         }
         slow->next = nullptr;
        ListNode* head1 = head;
         //3. Merge the Two halves
        while(head1!=nullptr){
            ListNode* temp = head1->next;
            head1->next = first;
            head1 = first;
            first = temp;
        }
    }
};