/* own Linked List Implementation
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() :data(0),next(NULL){}
    Node(int val) :data(val),next(NULL){}
    Node(int val,Node *next) :data(val),next(next){}
};

class MyLinkedList {
public:
    Node *head;
    Node *tail;
    int size;
    MyLinkedList() : head(NULL), tail(NULL), size(0) {}
    
    int get(int index) {
        if(index < 0 || index >= size){
            return -1;
        } else if(index == 0){
            return head->data;
        } else if(index == size -1) {
            return tail->data;
        } else {
            Node *temp = head;
            for(int i = 0; i < index; i++){
                temp = temp->next; // this will stop at index exactly
            }
            return temp->data;
        }
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val);
        if(size == 0){
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    
    void addAtTail(int val) {
        Node *newNode = new Node(val);
        if(size == 0){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size){
            return;
        } else if(index == 0){
            addAtHead(val);
            return;
        } else if(index == size){
            addAtTail(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *temp = head;
        // we use index-1 in loop because we need to stop before the index, so that we can access the index by temp->next
        for(int i = 0; i < index-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size){
            return;
        } else if(index == 0){
            Node *temp = head;
            head = head->next;
            delete temp;
            if(size == 1){
                tail = NULL;
            }
        } else {
            Node *temp = head;
            // we use index-1 in loop because we need to stop before the index, so that we can access the index by temp->next
            for(int i = 0; i < index-1; i++){
                temp = temp->next;
            }
            Node *remove = temp->next;
            temp->next = temp->next->next;
            delete remove;
            if(index == size-1)
                tail = temp;
        }
        size--;
    }
};

void displayLL(Node *headLL){
    while(headLL != NULL) {
        cout<<headLL->data<<"-->";
        headLL= headLL->next;
    }
    cout<<endl;
}

int main(int argc, char* argv[]) {
    vector<int> val{34,56,78,3,4,0};
    MyLinkedList temp;
    for(int i = 0; i < val.size(); i++) {
        temp.addAtHead(val[i]);
    }
    displayLL(temp.head);
    temp.addAtTail(100);
    displayLL(temp.head); 
    temp.addAtHead(345);
    displayLL(temp.head);
    cout<<"Value at Index 4 is : "<<temp.get(4)<<endl;
    temp.addAtIndex(6,777);
    displayLL(temp.head);
    temp.deleteAtIndex(2);
    displayLL(temp.head);

    return 0;
}
