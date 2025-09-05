/*  19. Remove Nth Node From End of List
Given the head of a linked list, remove the nth node from the end of the list and return its head. */
#include<iostream>
#include<vector>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node():data(0),next(nullptr){}
    Node(int x) : data(x), next(nullptr){}
    Node(int x, Node* next):data(x),next(next){}
};

void insertLL(Node *&headLL, int data) {
    if(headLL == NULL){
        headLL = new Node(data);
        return;
    }
    Node *temp = new Node(data);
    temp->next = headLL;
    headLL = temp;
}

void displayLL(Node* headLL) {
    while(headLL != NULL) {
        cout<< headLL->data<<"-->";
        headLL = headLL->next;
    }
    cout<<endl;
}
Node* removeNthFromEnd(Node* head, int n) {
    Node *fast = head;
    Node *slow = head;
    for(int i = 0; i < n; i++) {
        fast = fast->next; // Move the fast pointer to n times
    }
    if(fast == NULL) { // if fast reached NULL then it crosses the end of LL. so the node to be removed is head so remove head
        ListNode *delNode = head;
        head = head->next;
        delete delNode;
        return head;
    }
    while(fast->next != nullptr) {
        fast = fast->next; // Fast will reach the end
        slow = slow->next; // slow will reach the exact nth node from end
    }
    ListNode* delNode = slow->next;
    slow->next = slow->next->next; // slow next node is to be removed 
    delete delNode;
    return head;
}

int main(int argc, char*argv[]) {
    Node *head = NULL;
    vector<int> val{10,58,3,45,67};
    for(int i = 0; i < val.size(); i++) {
       insertLL(head,val[i]);
    }
    displayLL(head);
    head = removeNthFromEnd(head,2);
    displayLL(head);    
    return 0;
}

