/*
Example 2: 141. Linked List Cycle

Given the head of a linked list, determine if the linked list has a cycle.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
*/
#include<iostream>
#include<vector>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int data) : data(data),next(nullptr){}
};

Node* insertLL(Node *&head, int data) {
    Node* headLL = head;
    if(headLL == NULL){
        headLL = new Node(data);
        return headLL;
    }
    while(headLL->next != NULL)   {
        headLL = headLL->next;
    }
    Node *temp = new Node(data);
    temp->next = NULL;
    headLL->next = temp;
    return head;
}

void displayLL(Node* headLL) {
    while(headLL != NULL) {
        cout<< headLL->data<<"-->";
        headLL = headLL->next;
    }
    cout<<endl;
}

bool detectCycle(Node* headLL) {
    Node *fast = headLL;
    Node *small = headLL;
    while(fast != NULL and fast->next != NULL) {
        fast = fast->next->next;
        small = small->next;
        if(small == fast){
            return true;
        }
    }
    return false;
}

int main(int argc, char*argv[]) {
    Node *head = NULL;
    vector<int> val{10,34,55,66,77};
    for(int i = 0; i < val.size(); i++) {
        head = insertLL(head,val[i]);
    }
    displayLL(head);
    head->next->next->next->next->next = head;
    cout<<"Linked cycle is : "<<detectCycle(head)<<endl;    
    return 0;
}