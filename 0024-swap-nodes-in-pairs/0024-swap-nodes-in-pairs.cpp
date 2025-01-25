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
    ListNode* swapPairs(ListNode* head) {
        //dummyNode
        ListNode* dummyNode = new ListNode(0,head);
        ListNode* curr = head;
        ListNode* prev = dummyNode;

        while(curr!=nullptr && curr->next!=nullptr){
            //initialize
            ListNode* second = curr->next;
            ListNode* nextPair = curr->next->next;

            //swap
            second->next = curr;
            curr->next = nextPair;
            prev->next = second;

            //update
            prev = curr;
            curr = nextPair;
        }
        return dummyNode->next;

    }
};