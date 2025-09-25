#include<iostream>
#include<vector>

using namespace std;

// with vector implementation 
class VectorStack {
    private:
    vector<int> arr{};

    public:
    void push(int val){
        arr.push_back(val);
    }
    void pop(void){
        arr.pop_back();
    }
    int top(void){
        return arr.back();
    }
    bool empty(void){
        return arr.empty();
    }
    int size(void){
        return arr.size();
    }
};

void vectorImplementaion(void) {
    class VectorStack vSt;
    vSt.push(9);
    vSt.push(8);
    vSt.push(5);
    vSt.push(7);
    vSt.pop();
    vSt.pop();
    vSt.push(10);

    cout<<"Size of Vector Stack is : "<<vSt.size()<<endl;
    cout<<"Vector implementation of stack is : ";
    while(!vSt.empty()) {
        cout<<vSt.top()<<" ";
        vSt.pop();
    }
    cout<<endl;    
}


// with array implementation
class ArrayStack {
    public:
    int len = -1;
    int st[10];

    void push(int val){
        if(len == 9) {
            cout<<"Stack is Full!!!"<<endl;
        } else {
            len = len + 1;
            st[len] = val;
        }      
    }
    void pop(void){
        st[len] = 0;
        len--;
    }
    int top(void){
        return st[len];
    }
    bool empty(void){
        if(len >= 0){
            return 0;
        } else {
            return 1;
        }
    }
    int size(void){
        return len+1;
    }

};
void arrayImplementaion() {
    class ArrayStack aSt;
    aSt.push(9);
    aSt.push(8);
    aSt.push(5);
    aSt.push(7);
    aSt.push(1);
    aSt.push(3);
    aSt.push(2);
    aSt.push(4);
    aSt.push(6);
    aSt.push(10);
    aSt.push(19);
    aSt.push(56);
    aSt.push(78);
    aSt.pop();
    aSt.pop();
    aSt.push(189);

    cout<<"Size of Array Stack is : "<<aSt.size()<<endl;
    cout<<"Array implementation of stack is : ";
    int temp = 0;
    /*while(temp <= aSt.len) {
        cout<<aSt.st[temp]<<" ";
        temp++;
    }*/
    while(!aSt.empty()) {
        cout<<aSt.top()<<" ";
        aSt.pop();
    }
    cout<<endl;    
}

int main(int argc, char*argv[]) {
    vectorImplementaion();
    arrayImplementaion();
    return 0;
}