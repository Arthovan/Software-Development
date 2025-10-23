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
    ListNode* deleteTail(ListNode* head) {
        if(head == nullptr or head->next == nullptr){
            return nullptr;
        }
        ListNode *temp = head;
        ListNode *previous = nullptr;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        previous = temp->prev;
        previous->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return head;
    }
};