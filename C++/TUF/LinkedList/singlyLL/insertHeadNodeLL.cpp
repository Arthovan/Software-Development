/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* insertAtHead(ListNode* &head, int X) {
        if(head == NULL) {
            head = new ListNode(X);
            return head;
        }
        ListNode *temp = new ListNode(X);
        temp->next = head;
        return temp;
    }
};