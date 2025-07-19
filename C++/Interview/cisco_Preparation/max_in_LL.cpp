#include <exception>
#include<iostream>
#include <limits>

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

void insertAtEnd(Node* &tHead, int data){
    Node *temp = new Node(data);
    if(tHead == NULL){
        tHead = temp;
    }
    else{
        Node* currentHead = tHead;
        while(currentHead->next != NULL){
            currentHead = currentHead->next;          
        }
        currentHead->next = temp;
    }
}

void display(Node *tHead){
    while(tHead != NULL){
        cout<<tHead->data<<"==> ";
        tHead = tHead->next;
    }
    cout<<endl;
}

int findMax(Node *tHead){
    int maxVal = numeric_limits<int>::min();    //  store the lowest value possible
    if(tHead == NULL){
        cout<<"List is Empty"<<endl;
        return maxVal;
    }
    
    while(tHead != NULL){
        maxVal = max(maxVal, tHead->data);
        tHead = tHead->next;
    }
    return maxVal;
}
int main(){
    Node *head = NULL;
    insertAtEnd(head,10);
    insertAtEnd(head,-5);
    insertAtEnd(head,2000);
    insertAtEnd(head,2);
    insertAtEnd(head,100);
    insertAtEnd(head,-200);

    display(head);
    cout<<"MAx val : "<<findMax(head)<<endl;
    return 0;
}
