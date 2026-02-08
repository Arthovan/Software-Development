/*********** Vector - Dynamic Array *************
 * Vector are sequence containers representing the arrays that can change in size.
 * Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can also be accessed directly in O(1) time.
 * But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.
 * If vector size exceeds the vector will automatically create a new vector of size 2 times of original vector and copies the contents to new location.
 * Vectors can be used to create dynamic 1D & 2D arrays.
 * Unlike arrays, vectors are passed by value to a function, you may can still pass them by reference if need arises. */

 #include <iostream>
 #include <vector>

 using namespace std;

 int main(int argc, char *argv[]) {
    // Demo Vector
    vector<int> arr;    //  it doesnt have any elements and size is '0'

    // Size of the vector (No of elements)
    cout<<"Size of arr "<<arr.size()<<endl;   

    // Capacity of the vector (Actual memory allocated)
    cout<<"Capacity of arr "<<arr.capacity()<<endl;   

    vector<int> brr = {1,2,10,12,15};    // it has 5 elements in it
    cout<<"Size of brr "<<brr.size()<<endl;
    cout<<"Capacity of brr "<<brr.capacity()<<endl;  // capacity also shows 5 bcs we initialized vector with 5 elements so after adding new element into brr then its capacity will double.

    // Push Back O(1)
    brr.push_back(22); //add the element into vector at the end in O(1) 
    cout<<"Size of brr after push_back "<<brr.size()<<endl;
    cout<<"Capacity of brr after push_back "<<brr.capacity()<<endl; 

    // print all the elements
    for(int i=0; i<brr.size(); ++i) {
      cout<< brr[i]<< " ";
    }
    cout<<endl;

    // pop back (remove element at the end)
    brr.pop_back();
   
    for(int i=0; i<brr.size(); ++i) {
      cout<< brr[i]<< " ";
    }
    cout<<endl;

    // fill constructor
    vector<int> crr(10,7); // this creates a 10 elements with each has value 7 .

    for(int i=0; i<crr.size(); ++i) {
      cout<< crr[i]<< " ";
    }
    cout<<endl;
    return 0;
 }
 