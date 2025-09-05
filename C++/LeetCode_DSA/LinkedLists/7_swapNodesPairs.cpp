/* Example: 24. Swap Nodes in Pairs
Given the head of a linked list, swap every pair of nodes. For example, given a linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6, return a linked list 2 -> 1 -> 4 -> 3 -> 6 -> 5. 
*/
// Note : I need some time for this to understand
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

Node* reversePairs(Node* head) {
    // Check edge case: linked list has 0 or 1 nodes, just return
    if(head == NULL and head->next == NULL)
        return head;

    Node *curr = head->next;
    Node *prev = NULL;
    Node *nextNode = NULL;

    while(head != NULL and head->next != NULL) {
        if(prev != NULL){
            prev->next = head->next;
        }
        prev = head;
        nextNode = head->next->next;
        head->next->next = head;

        head->next = nextNode;
        head = nextNode;

    }
    return curr;
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