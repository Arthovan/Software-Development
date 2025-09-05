/* Need to work on it -------
	92. Reverse Linked List II
Given the head of a singly linked list and two integers left and right where left <= right, 
reverse the nodes of the list from position left to position right, and return the reversed list. */

ListNode* reverseBetween(ListNode* head, int left, int right) {          
	if(head == NULL or left == right) {
		return head;
	}
	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	ListNode *prev = dummy;
			
	for(int i = 1; i < left; i++) {
		prev = prev->next;
	}
	
	ListNode *curr = prev->next;
	
	for(int i = left; i < right; i++) {
		ListNode *nextNode = curr->next;
		curr->next = nextNode->next;
		nextNode->next = prev->next;
		prev->next = nextNode;
	}
	return dummy->next;   
}