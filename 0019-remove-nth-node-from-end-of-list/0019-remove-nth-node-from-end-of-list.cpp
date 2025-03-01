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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        if(head == nullptr && head->next == nullptr){
		return nullptr;
	}
    // if( && k == 1){
    //     return nullptr;
    // }
	
	ListNode* slow = head, *fast = head;
	for(int i = 0;i<k;i++){
		fast = fast->next;
	}
	if(!fast)
		{head = head->next;
		return head;}
	while(fast->next){
		slow = slow->next;
		fast = fast->next;
	}
	
	ListNode* temp = slow->next;
	slow->next = slow->next->next;
	delete temp;
	return head;
    }
};
