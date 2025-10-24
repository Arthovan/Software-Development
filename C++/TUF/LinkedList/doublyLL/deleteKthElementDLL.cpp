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
    ListNode* deleteHead(ListNode* head) {
        if(head == nullptr or head->next == nullptr) {
            return nullptr;
        }
        ListNode *temp = head;
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    ListNode* deleteTail(ListNode* head) {
        if(head == nullptr or head->next == nullptr) {
            return nullptr;
        }
        ListNode *temp = head;
        ListNode *prevNode = nullptr;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        prevNode = temp->prev;
        prevNode->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return head;
    }
    ListNode* deleteKthElement(ListNode* head, int k) {
        if(head == nullptr) {
            return nullptr;
        }
        ListNode *temp = head;
        int currentIndex = 0;

        while(temp != nullptr) {
            currentIndex++;
            if(currentIndex == k) {
                break;
            }
            temp = temp->next;
        }
        ListNode *prevNode = temp->prev;
        ListNode *nextNode = temp->next;
        if(prevNode == nullptr and nextNode == nullptr) {
            return nullptr;
        } 
        else if (prevNode == nullptr) {
            return deleteHead(head);
        } 
        else if(nextNode == nullptr) {
            return deleteTail(head);
        } else {
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            temp->next = nullptr;
            temp->prev = nullptr;
            delete temp;
            return head;
        }
    }
};