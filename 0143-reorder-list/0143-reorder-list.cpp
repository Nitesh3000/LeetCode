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
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr){
            return;
        }
        ListNode* middle = findMiddle(head);
        ListNode* head2 = middle->next;
        middle->next = nullptr;
        head2 = reverseList(head2);
        ListNode* temp = head2;
        while(temp!=nullptr){
            cout<<temp->val<<endl;
            temp = temp->next;
        }
        combine(head,head2);
        
    }
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next !=nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode = nullptr;
        ListNode* currentNode = head;
        while (currentNode != nullptr) {
            ListNode* nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        return prevNode;  
    }
    void combine(ListNode* head, ListNode* head2) {
        ListNode* head1 = head;
        while (head2 != nullptr) {
           
            ListNode* temp1 = head1->next;
            ListNode* temp2 = head2->next;

           
            head1->next = head2;
            head2->next = temp1;

          
            head1 = temp1;
            head2 = temp2;
        }
    }

};