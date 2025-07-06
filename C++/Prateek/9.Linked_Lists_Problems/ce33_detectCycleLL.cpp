/*  Using Floyd's Cycle-Finding Algorithm - O(n) Time and O(1) Space
    This idea is to use Floyd's Cycle-Finding Algorithm to find a loop in a linked list. It uses two pointers slow and fast, fast pointer move two steps ahead and slow will move one step ahead at a time.
Follow the steps below to solve the problem:    Traverse linked list using two pointers.
                                                Move one pointer(slow) by one step ahead and another pointer(fast) by two steps ahead.
                                                If these pointers meet at the same node then there is a loop. If pointers do not meet then the linked list doesn't have a loop.
*/
#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

Node* createLL(Node* headLL, int data){
    if(headLL == NULL){
        headLL = new Node(data);
        return headLL;
    }
    Node *temp = new Node(data);
    temp->next = headLL;
    headLL = temp;
    return headLL;
}

void displayLL(Node *headLL){
    while(headLL != NULL){
        cout<<headLL->data<<"==>";
        headLL =headLL->next;
    }
    cout<<endl;
}

bool detectCycle(Node *headLL){
    //base case, if no head 
    if(headLL == NULL)
        return false;
    Node *slow = headLL;
    Node *fast = headLL;

    while(fast != NULL and fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}
int main(){
    Node *head = NULL;
    vector<int> arr{4,7,9,10,3};
    int len = arr.size();
    for(int i=0;i<len;i++){
        head = createLL(head,arr[i]);
    }
    displayLL(head);

    //Create a cycle in a linked list
    head->next->next->next->next->next = head->next;
    
    if(detectCycle(head))
        cout<<"This LL has cycle"<<endl;
    else
        cout<<"This LL has no cycle in it"<<endl;
}
