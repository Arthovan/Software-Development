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
    ListNode * deleteHead(ListNode* head) {
        if(head == nullptr or head->next == nullptr) {
            return nullptr;
        }
   
        ListNode *previous = head;
        head = head->next;

        head->prev = nullptr;
        previous->next = NULL;
        
        delete previous;
        return head;
    }
};