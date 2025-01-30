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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head  == nullptr || head->next == nullptr){
            return head;
        }
        //count
        ListNode* curr = head;
        int count = 0;
        ListNode* tail = nullptr;
        while(curr!=nullptr){
            tail = curr;
            curr = curr->next;
            count++;
        }

        curr = head;
        k = k%count;
        if(k == 0){
            return head;
        }
        ListNode* prev = nullptr;
        for(int i = 0;i<count - k;i++){
            prev = curr;
            curr = curr->next;
        }
        if(prev!=nullptr)
            prev->next = nullptr;
        tail->next = head;
        head = curr;
        return head;
    }
};