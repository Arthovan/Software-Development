/* K Reverse    :  Given a linked list, write a function to reverse every k nodes (where k is an input to the function).
                Input   :   1->2->3->4->5->6->7->8->Null
                Output  :   3->2->1->6->5->4->8->7->Null
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

void reverseLLIterative(Node* &headLL){
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
    while(currentLL != NULL and cnt <= K){
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
    vector<int> arr{0,1,2,3,4};
    int K = 3;
    for(int i =0;i<arr.size();i++)
        createLL(head,arr[i]);
    displayLL(head);
    head = kReverseLL(head,K);
    displayLL(head);
}
