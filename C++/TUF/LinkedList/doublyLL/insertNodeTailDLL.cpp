/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution {
public:
    ListNode* insertBeforeTail(ListNode* head, int X) {
        if(head->next == nullptr) {
            ListNode * newNode = new ListNode(X,head,nullptr);
            head->prev = newNode;
            return newNode;
        }

        ListNode *temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        ListNode *newNode = new ListNode(X);
        ListNode *prevNode = temp->prev;

        newNode->prev = prevNode;
        newNode->next = temp;

        prevNode->next = newNode;
        temp->prev = newNode;

        return head;
    }
};