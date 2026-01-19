#include<iostream>
#include<vector>

using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

// Method to insert element at the head with the reference method
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
        for(int jump = 0; jump < pos; ++jump){
            localMLL = localMLL->next;
        }
        Node *temp = new Node(data);
        temp->next = localMLL->next;
        localMLL->next = temp;
    }
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
    displayLL(head);

    insertInMiddle(head,5,12);
    displayLL(head);
    
    insertInMiddle(head,0,6);
    displayLL(head);
    return 0;
}