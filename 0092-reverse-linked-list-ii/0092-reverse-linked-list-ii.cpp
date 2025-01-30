class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) {
            return head;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int i = 1;
        
       
        while (i < left) {
            prev = curr;
            curr = curr->next;
            i++;
        }

       
        ListNode* conn = prev; 
        ListNode* tail = curr; 
        
       
        ListNode* next = nullptr;
        while (i <= right) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }
        
       
        if (conn != nullptr) {
            conn->next = prev;
        } else {
            head = prev;
        }
        
        tail->next = curr;
        
        return head;
    }
};
