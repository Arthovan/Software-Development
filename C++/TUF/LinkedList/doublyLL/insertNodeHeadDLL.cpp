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
    ListNode* insertBeforeHead(ListNode* head, int X) {
        if(head == nullptr){
            return new ListNode(X,nullptr, nullptr);
        }
        ListNode *newNode = new ListNode(X);
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
};