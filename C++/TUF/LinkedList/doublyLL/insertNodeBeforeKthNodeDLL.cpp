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
    ListNode* insertBeforeKthPosition(ListNode* head, int X, int K) {
        if(K == 1) {
            ListNode *newNode = new ListNode(X);
            head->prev = newNode;
            newNode->next = head;
            return newNode;
        }
        ListNode * temp = head;
        int cnt = 0;
        while(temp != NULL) {
            cnt++;
            if(cnt == K) { 
                break;
            }
            temp = temp->next;
        }

        ListNode *prevNode = temp->prev;
        ListNode *newNode = new ListNode(X);
        
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = temp;
        temp->prev = newNode;
        return head;
        }
};