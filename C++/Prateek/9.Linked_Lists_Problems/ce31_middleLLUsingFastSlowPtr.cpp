/*
    Middle Element  :   This is an easy problem! Apply runner technique to find mid-point of a given linked list in a single pass.
    Input           :   Head of the Linked List is given as input.  1->2->3->4->5->6->7->8
    Output          :   4
*/

#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

// Method to insert element at the head with the refernce method
void insertAtHead(Node* &headLL, int data){
    // if node is empty and we need to insert an element
    if(headLL == NULL){
        headLL = new Node(data);
        return;
    }   

    // if node is not empty and we need to insert an element at head  
    Node *temp = new Node(data);
    temp->next = headLL;
    headLL = temp;  
}

// Display the entire LL elements 
void displayLL(Node *headDisplayLL){
    while(headDisplayLL != NULL){
        cout<<headDisplayLL->data<<"-->";
        headDisplayLL = headDisplayLL->next;
    }
    cout<<endl;   
}

int getMid(Node *head){
    //Complete this function to return data middle node
    Node *fastPtr=head, *slowPtr=head;
    while(fastPtr != NULL and fastPtr->next != NULL and fastPtr->next->next != NULL){
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }
    return slowPtr->data;
}

int main(){
    Node *head = NULL;
    vector<int> arr{1,2,3,4};
    for(int i=0;i<arr.size();i++)
        insertAtHead(head,arr[i]);
    cout<<"Insert at Head is done for head"<<endl;

    int data = getMid(head);
    cout<<"Mid data: "<<data<<endl;
    return 0;
}