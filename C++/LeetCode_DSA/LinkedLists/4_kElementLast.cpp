/* Example 3: Given the head of a linked list and an integer k, return the kth
node from the end.
For example, given the linked list that represents 1 -> 2 -> 3 -> 4 -> 5 and k = 2, return the node with value 4, as it is the 2nd node from the end. */
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int data):data(data),next(nullptr) {}
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

int kthNode(Node* headLL,int k) {
    Node* fast = headLL;
    Node* slow = headLL;
    for(int i = 0; i < k; i++){
        fast = fast->next;
    }
    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;        
    }
    return slow->data;
}
int main(int argc, char*argv[]) {
    Node *head = NULL;
    vector<int> val{10,7,3,45,67};
    for(int i = 0; i < val.size(); i++) {
       insertLL(head,val[i]);
    }
    displayLL(head);
    cout<<"Kth node of the Linked List is : "<<kthNode(head,2)<<endl;
    return 0;
}