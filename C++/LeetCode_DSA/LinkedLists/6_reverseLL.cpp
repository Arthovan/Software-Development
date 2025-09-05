/* Reverse a Linked List*/

#include <iostream>
#include <vector>

using namespace std;
struct Node {
    int data;
    Node *next = NULL;
    Node(int data) : data(data), next(nullptr){}
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

Node* reverseLL(Node* head) {
    Node *curr = head;
    Node *prev = NULL;
    Node *nextNode = NULL;
    while(curr != NULL) {
        nextNode = curr->next;  // first, make sure we don't lose the next node
        curr->next = prev;  // reverse the direction of the pointer
        prev = curr;        // set the current node to prev for the next node
        curr = nextNode;    // move on
    }
    return prev;
}
int main(int argc, char*argv[]) {
    Node *head = NULL;
    vector<int> val{10,58,3,45,67};
    for(int i = 0; i < val.size(); i++) {
       insertLL(head,val[i]);
    }
    displayLL(head);
    head = reverseLL(head);
    displayLL(head);
    return 0;
}