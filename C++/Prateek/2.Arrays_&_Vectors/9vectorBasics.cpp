#include<iostream>
#include<vector>
using namespace std;

int main(){
    /*  Array:   Its a collection of simillar data elements stored in a contiguous memory location  */

    //  Different ways to init an array
    int a[100];
    int b[100] = {0};
    int c[100] = {1,2,3,4,5};
    int d[] = {1,2,3,4,5};
    string fruits[4] = {"apple", "mango", "guava"};

    /*  Vector: Dynamic Array
        1.  Vectors are sequence containers representing arrays that can change in size.
        2.  Just like arrays, vectors use contiguous storage locations to store their elements, which means that their elements can also be accessed directly in O(1) time.
        3.  Unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.
        4.  Vectors can be used to create dynamic 1D & 2D arrays.
        5.  Unlike arrays, vectors are passed by value to a function, you may still pass them by reference if need arises.  */

    //  Demo
    vector<int> arr;
    vector<int> brr = {1,2,3,4,5};
    // Fill constructor 10 elements of each value is 7
    vector<int> crr(10,7);
    cout<<"size of arr: "<<arr.size()<<endl; //  size function returns the number of elements in the vector
    cout<<"size of brr: "<<brr.size()<<endl;

    cout<<"capacity of arr: "<<arr.capacity()<<endl; //  capacity function returns the actual memory allocated to this particular vector, 
    cout<<"capacity of brr: "<<brr.capacity()<<endl;
    /*  NOTE:   If we initialize the vector then the capacity function will return the same value as size.
                if we add another element after initialization then try capacity than we can see the difference.    */
                
    brr.push_back(6);   //  push_back function insert the element at the end of the vector array in constant time O(1).
    cout<<"size of brr after push_back: "<<brr.size()<<endl;
    cout<<"capacity of brr after push_back: "<<brr.capacity()<<endl;

    //  print all the elements using for loop
    for(int i=0;i<brr.size();i++){
        cout<<brr[i]<<" ";
    }
    cout<<endl;
    
    //  print all the elements using for each loop
    for(int element:brr){
        cout<<element<<" ";
    }
    cout<<endl;

    brr.pop_back(); //  pop_back function is used to remove the last element in the vector array

    for(int element:brr){
        cout<<element<<" ";
    }
    cout<<endl;
    

    //  2D vector
    cout<<"2D Vector"<<endl;
    //  unlike array we can have different number of elements in the sub array of vector
    vector<vector<int>> drr = { 
        {1,2,3},
        {4,5,6},
        {7,8,9,10},
        {11,12}
    };

    //  print all the elements using for loop
    for(int i=0;i<drr.size();i++){
        for(int j=0;j<drr[i].size();j++){
            cout<<drr[i][j]<<" ";
        }
        cout<<endl;
    }

    //  print all the elements using for each loop
    for(int i=0;i<drr.size();i++){
        for(int element:drr[i]){
            cout<<element<<" ";
        }
        cout<<endl;
    }

    return 0;
}
