#include<iostream>
#include<vector>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node():data(0),next(nullptr){}
    Node(int x) : data(x), next(nullptr){}
    Node(int x, Node* next):data(x),next(next){}
}*last;

Node* removeTailLL(Node *headLL) {
    // if there is no head then return simply
    if(headLL == NULL or headLL->next == NULL) {
        return NULL;
    }
    Node *temp = headLL; // hold the headLL
    Node *prev = NULL; 
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
    return headLL;
}

void insertEndLL(Node *&headLL, int data) {
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
Node* deleteMiddle(Node* head) {
    // if head has only one element then we need to return NULL
    if(head->next == NULL){
        return NULL;
    }
    Node *fast = head; // fast and slow pointer to find the mid
    Node *slow = head; // fast and slow pointer to find the mid
    Node *prev = head; // Prev to store the previous node
    while(fast != NULL and fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next; // as we need to skip the mid which is slow now thats why previous next element is slows next
    return head;
}
int main(int argc, char*argv[]) {
    Node *head = NULL;
    vector<int> val{10};
    for(int i = 0; i < val.size(); i++) {
       // insertHeadLL(head,val[i]);
       insertEndLL(head,val[i]);
    }
    displayLL(head);
    head = removeTailLL(head);
    displayLL(head);
    head = removeTailLL(head);
    displayLL(head);
    return 0;
}

