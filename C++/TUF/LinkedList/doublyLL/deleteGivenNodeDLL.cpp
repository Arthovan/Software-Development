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
    void deleteGivenNode(ListNode* node) {
        ListNode *nextNode = node->next;
        ListNode *prevNode = node->prev;

        if(nextNode == nullptr) {
            prevNode->next = nullptr;
            node->prev = nullptr;
            delete node;
            return;
        }

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        node->next = nullptr;
        node->prev = nullptr;

        delete node;
    }
};