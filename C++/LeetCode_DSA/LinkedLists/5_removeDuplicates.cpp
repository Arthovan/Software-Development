/*  83. Remove Duplicates from Sorted List
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well. */

#include<iostream>
#include<vector>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node():data(0),next(nullptr){}
    Node(int x) : data(x), next(nullptr){}
    Node(int x, Node* next):data(x),next(next){}
}*last;

void insertEndLL(Node *&headLL, int data) {
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

Node* deleteDuplicates(Node* head) {
    Node* current = head;
        
    while(current != NULL and current->next != NULL) {
        if(current->next->data == current->data){
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
    return head;
}

int main(int argc, char*argv[]) {
    Node *head = NULL;
    vector<int> val{1,1,2,3,3};
    for(int i = 0; i < val.size(); i++) {
       insertEndLL(head,val[i]);
    }
    displayLL(head);
    head = deleteDuplicates(head);
    displayLL(head);    
    return 0;
}

