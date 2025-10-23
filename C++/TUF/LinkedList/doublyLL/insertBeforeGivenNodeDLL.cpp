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
    void insertBeforeGivenNode(ListNode* node, int X) {
        ListNode *prevNode = node->prev;

        ListNode *newNode = new ListNode(X);
        prevNode->next = newNode;
        node->prev = newNode;
        newNode->prev = prevNode;
        newNode->next = node;
        return;
    }
};