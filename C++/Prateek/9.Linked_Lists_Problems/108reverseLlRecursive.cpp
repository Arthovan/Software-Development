//#include <cstddef>
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

// Insert data at the specific position
void insertInMiddle(Node* &headMLL, int pos, int data){
    if(pos==0){
        insertAtHead(headMLL,data);
    }
    else{
        Node *localMLL = headMLL;
        for(int jump=0;jump<pos;jump++){
            localMLL =localMLL->next;
        }
        Node *temp = new Node(data);
        temp->next = localMLL->next;
        localMLL->next = temp;
    }
}

//  Reverse the links alone not the data
Node* reverseLLRecursive(Node* head){
    // Base case: if head is null or only one node, return head
    if(head == NULL or head->next == NULL)
        return head;
    // Recursive case: reverse the rest of the list
    Node *sHead = reverseLLRecursive(head->next);

    // Adjust the pointers
    head->next->next = head;    // Make the next node point to the current node
    head->next = NULL;          // Set the current node's next to null  
    return sHead;               // Return the new head of the reversed list, this is always last element node bcs its the new head after link reversal
}

// Display the entire LL elements 
void displayLL(Node *headDisplayLL){
    while(headDisplayLL != NULL){
        cout<<headDisplayLL->data<<"-->";
        headDisplayLL = headDisplayLL->next;
    }
    cout<<endl;   
}

int main(){
    Node *head = NULL;
    vector<int> arr{2,-7,4,5,8,0};
    for(int i=0;i<arr.size();i++)
        insertAtHead(head,arr[i]);
    cout<<"Insert at Head is done"<<endl;
    displayLL(head);

    cout<<"Insert at middle"<<endl;
    insertInMiddle(head,5,12);
    displayLL(head);
    
    cout<<"Insert at middle"<<endl;
    insertInMiddle(head,0,6);
    displayLL(head);

    cout<<"Reverse a LL recursively"<<endl;
    head = reverseLLRecursive(head);
    displayLL(head);

    return 0;
}