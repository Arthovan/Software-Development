/* Example 1: Given the head of a linked list with an odd number of nodes head, return the value of the node in the middle.

For example, given a linked list that represents 1 -> 2 -> 3 -> 4 -> 5, return 3. */

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

int midLL(Node* headLL) {
    Node* fast = headLL;
    Node* slow = headLL;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}
int main(int argc, char*argv[]) {
    Node *head = NULL;
    vector<int> val{10,67,3,45,67};
    for(int i = 0; i < val.size(); i++) {
       insertLL(head,val[i]);
    }
    displayLL(head);
    cout<<"Mid of Linked List is : "<<midLL(head)<<endl;
    return 0;
}