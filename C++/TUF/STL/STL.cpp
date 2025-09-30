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
    cout<<endl<<"Number of elements in the vector is : "<<vec.size() <<endl; // tell us how many elements are there in the vector
    
    /********* traverse the vector ***********/
    cout<<"Traverse of vector : ";
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

    cout<<"Vector at spceific location is : "<<vec.at(2)<<endl;
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
    // removes the specific indices
    vec.erase(vec.begin()+1, vec.end()-1);
    for(auto i : vec) {
        cout<< i << " ";
    }
    cout<<endl;

    /******** Clear ********/
     cout<<"Vector size before clear is : "<<vec.size()<<endl;
    vec.clear();    //  clear the vector and make it as empty
    cout<<"Vector size after clear is : "<<vec.size()<<endl;

    /************** swap ************/
    vector<int> vec1{3,4,5};
    vector<int> vec2{6,7,8};
    swap(vec1,vec2);
    for(auto i : vec1) {
        cout<<i<<" ";
    }
    cout<<endl;

    /************ insert ********/
    vector<int> vec3 {7,8,9,10,11};
    vec3.insert(vec3.begin(),4);
    vec3.insert(vec3.begin()+2,5);
    cout<<"Vector after insert is : ";
    for(auto i : vec3){
        cout<<i<<" ";
    }
    cout<<endl;
}
void explainList() {
    list<int> ls;
    // list is also like vector but it has push_front and front in it 
    ls.push_back(1);
    ls.push_front(8);
    cout<<ls.front()<<endl;
}

void explainStack() {
    // LIFO
    stack<int> st;
    st.push(1);     // push elements into the stack
    st.push(2);
    st.push(5);
    st.emplace(8);  //  same as push
    cout<<endl<<"Top of stack is "<<st.top()<<endl;   // return the top of the stack
    st.pop();       // remove the top element in the stack
    cout<<"Top of stack is "<<st.top()<<endl;
    cout<<"Size of stack is "<<st.size()<<endl; //  Return the number of elements in the stack
    st.empty() == 1 ? cout<<"Stack is empty"<<endl : cout<<"Stack is not empty"<<endl;
    //swap();         //  even we can use the swap function too in stack
    cout<<"Stack elements are : ";
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}


void explainQueue() {
    // FIFO
    queue<int> q;
    q.push(3);      // push elements into the queue
    q.push(2);
    q.push(7);
    q.emplace(9);   //  same as push
    cout<<endl<<"Front of queue is "<<q.front()<<endl;   // return the top of the queue
    q.pop();        // remove the front element in the queue
    cout<<"Top of queue is "<<q.back()<<endl;
    cout<<"Size of queue is "<<q.size()<<endl; //  Return the number of elements in the queue
    q.empty() == 1 ? cout<<"Queue is empty"<<endl : cout<<"Queue is not empty"<<endl;
    //swap();         //  even we can use the swap function too in queue
    cout<<"Queue elements are : ";
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

void explainPQ() { // front and back wont support here
    // stores the highest element at the top
    priority_queue<int> pq; //  this way the PQ stores the highest element at the top
    priority_queue<int, vector<int>, greater<int>> pq_small;    // this way the PQ stores the lowest element at the top
    pq.push(7);      // push elements into the priority queue
    pq.push(2);
    pq.push(11);
    pq.emplace(1);   //  same as push
    pq.pop();        // remove the front element in the priority queue
    cout<<endl<<"Size of priority queue is "<<pq.size()<<endl;      //  Return the number of elements in the queue
    pq.empty() == 1 ? cout<<"Priority Queue is empty"<<endl : cout<<"Priority Queue is not empty"<<endl;
    //swap();       //  even we can use the swap function too in priority queue
    cout<<"Priority Queue elements are : ";
    while(!pq.empty()) {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;

    pq_small.push(4);
    pq_small.push(15);
    pq_small.push(1);
    while(!pq_small.empty()) {
        cout<<pq_small.top()<<" ";
        pq_small.pop();
    }
    cout<<endl;
}

void explainSet() {
    set<int> st;
    st.insert(2);
    st.emplace(15);     //  same as insert
    st.insert(45);
    st.insert(23);
    st.insert(23);
    st.insert(23);      //  even though we store multiple elements still set retain only 1 unique element of it
    cout<<endl<<"Set elements are : ";
    for(auto it : st) {
        cout<<it<<" ";
    }
    cout<<endl;

    auto it = st.find(12);  //  if set cant able to find the element 12 then it will store the end iterator which is element next to last element
    if(it != st.end()){     //  thats why we are checking whether its a end iterator or not
        cout<<*it;
    }
    cout<<endl;

    cout<<"Elements is there or not : "<<st.count(23)<<endl;    //  it will show whether the element is there or not

    auto it1 = st.end();     //  store the last element next location
    it1--;   //  comes to last element location
    it1--;   //  comes to last before element location 
    st.erase(it1);   //  remember we need to use always the iterator in the erase function
    cout<<endl<<"Set elements are : ";
    for(auto it : st) {
        cout<<it<<" ";
    }
    cout<<endl;
    st.insert(23);
    st.insert(45);

    cout<<endl<<"Set elements are : ";
    for(auto it : st) {
        cout<<it<<" ";
    }
    cout<<endl;

    auto it2 = st.begin();
    auto it3 = st.end();
    it2++;
    it3--;
    st.erase(it2,it3);
    cout<<endl<<"Set elements are : ";
    for(auto it : st) {
        cout<<it<<" ";
    }
    cout<<endl;

    st.insert(22);
    st.insert(56);

    cout<<endl<<"Set elements are : ";
    for(auto it : st) {
        cout<<it<<" ";
    }
    cout<<endl;

    // Upper bound
    // that is <= number given, if no number is near to lower bound it moves to the end iterator next element
    auto valuer = st.lower_bound(2);
    cout<<"Lower Bound of valuer is : "<<*valuer<<endl;
    // lower bound
    // that is > number given, , if no number is near to upper bound it moves to the end iterator next element
    auto values = st.upper_bound(45);
    cout<<"Upper Bound of values is : "<<*values<<endl;
}

int main(int argc, char* argv[]) {
    explainPair();
    explainVector();    //  vector implementation is array by nature in C++
    explainList();      //  list and deque are linked list implementation in C++
    explainStack();
    explainQueue();
    explainPQ();        //  priority queue which stores the highest value at the top, which is internally a heap
    explainSet();       //  set is a data structure which stores unique data elements in ascending order
    return 0;
}