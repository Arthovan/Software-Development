/*
    Kth Element     :   Implement a function that returns the Kth last of element from the linked list, in a single pass. You can assume K will be less than / equal to length of linked list.
                        (Hint : Use two pointers similar to Runner Technique)
    Input           :   You will get head of the linked list.1 -> 2 -> 3 -> 4 -> 5 ->6 ->7
                        K = 3
    Output          :   5
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

int kthLastElement(Node *head, int k){
    //Complete this function to return kth last element
    Node *mainPtr = head, *refPtr = head;
    for(int i=1;i<k;i++)
        refPtr = refPtr->next;
        
    while(refPtr->next != NULL){
        refPtr = refPtr->next;
        mainPtr = mainPtr->next;
    }
    return mainPtr->data;
}
int main(){
    Node *head = NULL;
    vector<int> arr{45,56,-2,10};
    for(int i=0;i<arr.size();i++)
        insertAtHead(head,arr[i]);
    cout<<"Insert at Head is done for head"<<endl;

    int data = kthLastElement(head,2);
    cout<<"Kth from last of LL: "<<data<<endl;
    return 0;
}