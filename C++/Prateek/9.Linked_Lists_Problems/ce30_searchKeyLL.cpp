#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;


class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next =NULL;
    }
};

// Created a insert method with return the head method and we can use here instance as well which we will see in the upcoming lectures
Node* insertAtHead(Node *headLL,int data){
    if(headLL == NULL){
        headLL = new Node(data);
        return headLL;
    }
    Node *temp = new Node(data);
    temp->next = headLL;
    headLL = temp;
    return headLL;  
}

// Checking whether the key is present in the linked list or not
bool isPresent(Node * head, int key){
    //Complete this function 
    Node *temp = head;
    while(temp != NULL){
        if(key == temp->data)
            return true;
        temp=temp->next;
    }
    return false;
}

int main(){
    vector<int> arr{2,-7,4,5,8,0};
    Node *head = NULL;
    for(int i=0;i<arr.size();i++){
        head = insertAtHead(head,arr[i]);
    }
    if(isPresent(head,-7))
        cout<<"Element is Present"<<endl;
    return 0;
}