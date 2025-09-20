/* 328. Odd Even Linked List

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity. */

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

Node* oddEvenList(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node *even = head->next;    // to store the even head starting for traverse
    Node *odd = head;           // to store the odd head starting for traverse
    Node *evenHead = even;      // to store the even head to use it at last
    while(even != NULL and even->next != NULL) {
        odd->next = odd->next->next;    // update the odd next
        odd = odd->next;                // update the odd
        even->next = even->next->next;  // update the even next
        even = even->next;              // update the even
    }
    odd->next = evenHead;               // update the end with even head so that odd and even will be merged one after another
    return head;
}

int main(int argc, char*argv[]) {
    Node *head = NULL;
    vector<int> temp{1,2,3,4,5};
    for(int i = 0; i < temp.size(); i++) {
        insertLLEnd(head, temp[i]);
    }
    displayLL(head);
    head = oddEvenList(head);
    displayLL(head);
    return 0;
}
