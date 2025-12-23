/* K Reverse    :  Given a linked list, write a function to reverse nodes from m to n. (where m is 3 and n is 5)
                Input   :   1->2->3->4->5->6->7->8->Null
                Output  :   1->2->3->6->5->4->7->8->Null
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

void createLL(Node* &headLL, int data){
    if(headLL == NULL){
        headLL = new Node(data);
        return;
    }
    Node *temp = new Node(data);
    temp->next = headLL;
    headLL = temp;
}

void displayLL(Node *headLL){
    while(headLL != NULL){
        cout<<headLL->data<<"==>";
        headLL= headLL->next;
    }
    cout<<endl;
}

void reverseLLIterative(Node* &headLL, int m, int n){
    Node *previousLL = NULL, *nextLL = NULL, *currentLL = headLL;
    while(currentLL != NULL){
        nextLL = currentLL->next;
        currentLL->next = previousLL;

        previousLL = currentLL;
        currentLL = nextLL;
    }
    headLL = previousLL;
}

Node* kReverseLL(Node *&headLL,int K){
    Node *previouLL = NULL, *nextLL = NULL, *currentLL = headLL;
    int cnt = 1;
    while(currentLL != NULL and cnt<=K){
        nextLL = currentLL->next;
        currentLL->next = previouLL;

        previouLL = currentLL;
        currentLL = nextLL;
        cnt++;
    }
    if(nextLL != NULL){
        headLL->next = kReverseLL(nextLL,K);
    }
    return previouLL;
}

int main(){
    Node *head = NULL;
    vector<int> arr{1,2,3,4,5,6,7,8};
    int m = 3, n = 5;
    for(int i =0;i<arr.size();i++)
        createLL(head,arr[i]);
    displayLL(head);
    head = reverseLLIterative(head,m,n);
    displayLL(head);
}
