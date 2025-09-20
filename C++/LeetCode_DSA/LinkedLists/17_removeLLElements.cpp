/* 203. Remove Linked List Elements
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head. */

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node():data(0),next(nullptr){}
    Node(int x) : data(x), next(nullptr){}
    Node(int x, Node* next):data(x),next(next){}
}*last;

void insertLLEnd(Node *&headLL, int data) {
    if(headLL == NULL){
        headLL = new Node(data);
        last = headLL;
        return;
    }
    Node *temp = new Node(data);
    last->next = temp;
    last = temp;
}

void displayLL(Node* headLL) {
    while(headLL != NULL) {
        cout<< headLL->data<<"-->";
        headLL = headLL->next;
    }
    cout<<endl;
}

Node* removeElements(Node* head, int val) {
    // we are creating a LL with 0-->head-->, Like this so that if we have to remove head elements then we can remove it in this way
    Node *dummy = new Node(0,head);
    Node *ans = dummy;
    while(dummy !=NULL){
        // we are removing the elements until its not equal to the val
        while(dummy->next != NULL and dummy->next->data == val){
            dummy->next = dummy->next->next; 
        }
        // if not equal to val then traverse the dummy
        dummy = dummy->next;
    }
    // ans first element is 0 thats why we do ans->next so that head is the starting element
    return ans->next;        
}

int main(int argc, char*argv[]) {
    Node *head = NULL;
    vector<int> temp{1,2,6,3,4,5,6};
    for(int i = 0; i < temp.size(); i++) {
        insertLLEnd(head, temp[i]);
    }
    displayLL(head);
    head = removeElements(head,6);
    displayLL(head);
    return 0;
}
