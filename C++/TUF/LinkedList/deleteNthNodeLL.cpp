/*  2095. Delete the Middle Node of a Linked List
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively. */
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
Node* deleteNthNode(Node* head,int n) {
    // if head has no element then we need to return NULL
    if(head == NULL){
        return NULL;
    }
    // if n is 1 then we need to delete the first element which is head
    if(n == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    Node *temp = head; // temp to traverse the node
    Node *prev = NULL; // prev to store the prev node
    for(int i = 1; i < n; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
    return head;
}
int main(int argc, char*argv[]) {
    Node *head = NULL;
    vector<int> val{10,58,3,45,67};
    for(int i = 0; i < val.size(); i++) {
       insertLL(head,val[i]);
    }
    displayLL(head);
    head = deleteNthNode(head, 5);
    displayLL(head);    
    return 0;
}

