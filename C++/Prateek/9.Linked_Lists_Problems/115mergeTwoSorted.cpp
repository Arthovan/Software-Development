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

// Display the entire LL elements 
void displayLL(Node *headDisplayLL){
    while(headDisplayLL != NULL){
        cout<<headDisplayLL->data<<"-->";
        headDisplayLL = headDisplayLL->next;
    }
    cout<<endl;   
}

Node* mergeTwoSortedLL(Node *a, Node *b){
    // Base Case
    if(a == NULL)   return b;   //  If "a" LL is empty then only "b" data remains so return b
    if(b == NULL)   return a;   //  If "b" LL is empty then only "a" data remains so return a

    if(a->data < b->data){  //  Comapre which LL data is small
        a->next = mergeTwoSortedLL(a->next, b); //  temp head next is again the sorted call which will return the small data and merge call and so on 
        return a;
    }
    else{
        b->next = mergeTwoSortedLL(a, b->next);
        return b;
    }
}

int main(){
    Node *head = NULL;
    Node *head1 = NULL;
    // input sould be of sorted so only I have inlcuded the elements like this
    vector<int> arr{4,3,2,1};
    vector<int> brr{7,6,5,0};
    for(int i=0;i<arr.size();i++)
        insertAtHead(head,arr[i]);
    cout<<"Insert at Head is done for head"<<endl;    // elements are now 1,2,3,4
    displayLL(head);

    for(int i=0;i<brr.size();i++)
        insertAtHead(head,brr[i]);
    cout<<"Insert at Head is done for head1"<<endl;    //  elements are now 0,5,6,7 
    displayLL(head1);
    
    head = mergeTwoSortedLL(head,head1);
    displayLL(head);
    return 0;
}

