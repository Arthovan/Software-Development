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
    ListNode* deleteTail(ListNode* &head) {
        // tail means last Node of LL so NULL wont be counted as last Node, if head is NULL and has only one Node then return NULL
        if(head == NULL or head->next == NULL) {
            return NULL;
        }
        ListNode *temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
        return head;
    }
};
