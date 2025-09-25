#include<bits/stdc++.h>
//#include<vector>

using namespace std;

void explainPair() {
    pair<int,int> pr1 = make_pair(2,8);         //  pair is just to store a two values in a single variable, Ex: instead of storing a int in two varaibles we are storing in a single variable
    cout<<pr1.first<<" "<<pr1.second<<endl;

    pair<int,char> pr2 = make_pair(3,'V');      // Ex: instead of storing a int and char in two varaibles we are storing in a single variable 
    cout<<pr2.first<<" "<<pr2.second<<endl;

    pair<pair<int,char>,int> pr3 = {{7,'h'},5}; // created a pair of int char and int in this to see the nested pair concept
    cout<<pr3.first.first<<" "<<pr3.first.second<<" "<<pr3.second<<endl;    // also see this to check how we are accessing the elements
}

void explainVector() {
    // Array is of fixed size, while creating itself we fixed the size, what if we need a dynamic array thats where vector comes into the picture
    vector<int> vec;    // vector is of sequence container of dynamic in size, if we add elements greater than the size of the vector then it always doubles its size. 
    // Ex: if a vector is of size 7 initially then if we add 8th element into it then it will become 14, likewise it will keep on double itself whenever it encounter the new element of greater size (7, 14,28, 56, 112 and so on)
    vec.push_back(1);   //  push the elements into the vector 
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(4);
    vec.emplace_back(5); // emplace also the same thing as like push_back
    cout<<"Number of elements in the vector is : "<<vec.size() <<endl; // tell us how many elements are there in the vector
    
    /********* traverse the vector ***********/
    for(int i = 0; i < vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;

    //travese the vector using iterator
    vector<int>::iterator beginItr = vec.begin();               //  Iterator beginItr will holds the first element address
    vector<int>::iterator endItr = vec.end();                   //  Iterator endItr will always holds the next element of end element, remember this 
    for(vector<int>::iterator i = beginItr; i < endItr; i++) {  // as the endItr holds the ends next element thats why we used i < endItr here
        cout<< *i << " ";
    }
    cout<<endl;

    //travese the vector using iterator with auto keyword
    auto bItr = vec.begin();            //  Iterator beginItr will holds the first element address
    auto eItr = vec.end();              //  Iterator endItr will always holds the next element of end element, remember this 
    for(auto i = bItr; i < eItr; i++) { // as the endItr holds the ends next element thats why we used i < endItr here
        cout<< *i << " ";
    }
    cout<<endl;

    // traverse using for each loop
    for(auto i : vec) {
        cout<< i << " ";
    }
    cout<<endl;
    //////////////////////////////////////

    /****** Reverse iterator ************/
    auto reverseBegin = vec.rbegin();   // points to the end element address
    auto reverseEnd = vec.rend();       // points to the element before first element, remember this
    for(auto i = reverseBegin; i < reverseEnd; i++) {
        cout<< *i << " ";
    }
    cout<<endl;

    /************ Vector initialization ******************/
    vector<int> val(5); // initialized the vector with 5 elements of value 0
    val.push_back(8);   //  adding 8 after that
    val.push_back(10);  //  adding 10 after that
    for(auto i : val) { // it will print 7 elements from 
        cout<< i <<" ";
    }
    cout<<endl;

    // another method
    vector<int> brr(5,6);   // initialized the vector with 5 elements of value 6
    for(auto i : brr) {
        cout<< i <<" ";
    }
    cout<<endl;

    // another method
    vector<int> crr = {10,12};
    for(auto i : crr) {
        cout<< i << " ";
    }
    cout<<endl;
    
    // copying the vector
    vector<int> dupVector(val);
    for(auto i : dupVector) {
        cout<< i << " ";
    }
    cout<<endl;

    // printing only specific elements
    vector<int> dVector(val.begin()+1,val.end()-1);
    for(auto i : dVector) {
        cout<< i << " ";
    }
    cout<<endl;
    ////////////////////////////////////////////////////

    dupVector.pop_back();               //  removes the last element
    cout<<dupVector.back()<<endl;       //  we can access the last element
    cout<<dupVector.front()<<endl;      //  we can access the front element

    /****** Erase **********/
    vec.erase(vec.begin());             // removes the first element, remember that we need to use iterator while using the erase function
    for(auto i : vec) {
        cout<< i << " ";
    }
    cout<<endl;

    vec.erase(vec.begin()+1, vec.end()-1);
    for(auto i : vec) {
        cout<< i << " ";
    }
    cout<<endl;
}

int main(int argc, char* argv[]) {
    explainPair();
    explainVector();
    return 0;
}


/*  2095. Delete the Middle Node of a Linked List
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively. */
#include<iostream>
#include<vector>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node():data(0),next(nullptr){}
    Node(int x) : data(x), next(nullptr){}
    Node(int x, Node* next):data(x),next(next){}
};

void insertLL(Node *&headLL, int data) {
    if(headLL == NULL){
        headLL = new Node(data);
        return;
    }
    Node *temp = new Node(data);
    temp->next = headLL;
    headLL = temp;
}

void displayLL(Node* headLL) {
    while(headLL != NULL) {
        cout<< headLL->data<<"-->";
        headLL = headLL->next;
    }
    cout<<endl;
}
Node* deleteNthNode(Node* head,int n) {
    // if head has no element then we need to return NULL
    if(head == NULL){
        return NULL;
    }
    // if n is 1 then we need to delete the first element which is head
    if(n == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    Node *temp = head; // temp to traverse the node
    Node *prev = NULL; // prev to store the prev node
    for(int i = 1; i < n; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete temp;
    return head;
}
int main(int argc, char*argv[]) {
    Node *head = NULL;
    vector<int> val{10,58,3,45,67};
    for(int i = 0; i < val.size(); i++) {
       insertLL(head,val[i]);
    }
    displayLL(head);
    head = deleteNthNode(head, 5);
    displayLL(head);    
    return 0;
}


