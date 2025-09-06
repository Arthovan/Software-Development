/* 1290. Convert Binary Number in a Linked List to Integer
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

Approach :
1. Initialize result = 0 (start with 0 in decimal).
2. Traverse the linked list:
    For each bit (0 or 1):
        * Shift result left by 1 bit (equivalent to multiplying by 2).
        * Add the current bit using bitwise OR (|) or simple addition.
3. Return result, which now holds the decimal value. */

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

int getDecimalValue(Node* head) {
    unsigned int dec_val = 0;
    while(head != NULL){
        dec_val = (dec_val << 1) + head->data;
        head = head->next;
    }
    return dec_val;
}

int main(int argc, char*argv[]) {
    Node *head = NULL;
    vector<int> temp{1,0,0,1,1,0,0};
    for(int i = 0; i < temp.size(); i++) {
        insertLLEnd(head, temp[i]);
    }
    displayLL(head);
    cout<<"Decimal Value of the Linked List numbers :"<<getDecimalValue(head)<<endl;  
    return 0;
}
