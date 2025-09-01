#include <iostream>

using namespace std;

class Vector{
    int *arr;
    int currentSize;
    int maxSize;

    public:
    Vector(int max_size = 1){
        currentSize = 0;
        maxSize = max_size;
        arr = new int[ms];
    }

    void push_back(int data) {
        if(currentSize == maxSize){
            int *oldArr = arr;
            maxSize = 2*maxSize;
            arr = new int[maxSize];
            for(int i = 0; i < maxSize; i++) {
                arr[i] = oldArr[i];
            }
            delete [] oldArr;
        }
        arr[currentSize] = data;
        currentSize++;
    }
    void pop_back() {
        if(currentSize > 0) {
            cs--;
        }
    }
    bool isEmpty() {
        return cs==0;
    }
    int front() {
        return arr[0];
    }
    int back() {
        return arr[cs-1];
    }
    int at(int position) {
        return arr[position];
    }
    int size() {
        return currentSize;
    }
    int capacity() {
        return maxSize;
    }
    // operator overlodaing whenever it sees v[i] it returns the value
    int operator[](int i){
        return arr[i];
    }
}
int main(int argc, char*argv[]){
    Vector v(5);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(15);
    v.push_back(6);
    v.pop_back();

    cout<< v.front() <<endl;
    cout<< v.back() <<endl;

    cout<< v.at(2) <<endl;

    cout<< v.size() <<endl;
    cout<< v.capacity() <<endl;

    for(int i =0; i < v.size(); i++) {
        cout<< v.at[i] <<",";
    }
    // below code is same as above but with operator overloading
    for(int i =0; i < v.size(); i++) {
        cout<< v[i] <<",";
    }

    return 0;
}