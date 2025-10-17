# Tree

A data structure which stores the data in the hierrachical manner is called "Tree".

## Types

* Binary Tree
* Binary Search Tree
* N-array Tree

## Binary Tree

A tree where node can have maximum of 2 children.

![Parent-Child Relation](./binary-tree-data-structure.webp)

### Types of Binary Tree

#### Full BT

All nodes must have 2 or 0 children

#### Complete BT

* All levels must be completely filled except the last level.
* The last levels has all nodes in left as possible.

#### Perfect BT

* All leaf nodes are at the same level.
* All non leaf nodes must have 2 children.

#### Balanced BT

* Height difference between left and right subtree ar any node must be a maximum of 1.

#### Degenerate BT

![Binary Tree Types](./types_of_BST.jpeg)

### Traversal Techniques

#### Inorder Traversal 

* Left->Root->Right
* Time Complexity : O(N) --> Because it has to traverse all the nodes
* Space Complexity : O(1ogN) --> Incase of Balanced Binary Tree, O(N) in worst case

#### Preorder Travesal - Root->Left->Right

#### Postorder Traversal - Left->Right->Root

/*  Insertion sort : inserting the elements by comparing its value to every elements and insert in the correct place of sorted order
    Time complexity O(1) - O(n^2) -> Because of shifting an elements, if at 1st place then O(1), if not O(n^2)
    Space complexity O(1) 
    Insertion sort is designed for linked list and in array its convenient
    Adaptive : Yes minimum time required to swap elements is O(n)
*/
/*  Comparision of Bubble Sort and Insertion Sort
    ----------------------------------------------------------------
            List            |   Bubble Sort |  Insertion Sort
    ----------------------------------------------------------------
    Minimum Comparision     |   O(n)        |   O(n)
    Maximum Comparision     |   O(n^2)      |   O(n^2)
    Minimum Swap            |   O(1)        |   O(1)
    Maximum Swap            |   O(n^2)      |   O(n^2)
    Adaptive                |   YES         |   YES
    Stable                  |   YES         |   YES                 // Stable means maintain the order even if we have duplicates
    Linked List             |   NO          |   YES
    K Passes                |   YES         |   NO 
*/       



#include<iostream>
using namespace std;

//  normal insertion sort 
void insertionSort(int arr[], int size){
    int i=0,j=0,temp=0;
    for(i=1;i<size;i++){    //  We always start to compare the 2nd element to 1st element in insertion sort so only we have i=1
        temp=arr[i];    
        j=i-1;
        while(j > -1 && arr[j]>temp){   // index should not go below 0 so only we are checking it here, also check whether previous is greater than current element
            arr[j+1] = arr[j];          //  assign previous value to current
            j--;                        //  decrement the j
        }
        arr[j+1] = temp;                //  if while pass this will store the 
    }
}

int main(){
    int A[] = {3,7,9,10,6,5,12,4,11,2}, n=10,i;
    //int A[] = {2,3,4,5}, n=4,i;
    cout<<"Before Sort: ";
    for(int i:A)
        cout<<i<<" ";
    cout<<endl;
    insertionSort(A,n);
    cout<<"After Sort: ";
    for(int i:A)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
/*  Merge Sort : Its a divide and conquer algorithm, input array is divided into 2 parts, where both the parts will split into again and again until one element is there 
    then the sorting will happen.
*/
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &a, int startIndex, int endIndex){
    int i = startIndex;
    int midIndex = (startIndex + endIndex)/2;
    int j = midIndex + 1;
    vector<int> temp;

    while(i <= midIndex and j <= endIndex){
        if(a[i] < a[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
            temp.push_back(a[j]);
            j++;
        }
    }
    //  copy remaining elements from first array
    while(i <= midIndex){
        temp.push_back(a[i++]);
    }
    //  copy remaining elements from second array
    while(j <= endIndex){
        temp.push_back(a[j++]);
    }
    //  copy back the elements from temp to original array
    int k = 0;
    for(int idx = startIndex; idx <= endIndex; idx++){
        a[idx] = temp[k++];
    }
    return;
}

void mergeSort(vector<int> &a,int startIndex, int endIndex){
    //  baseCase --> if array has 0 0r 1 element then no need to sort
    if(startIndex >= endIndex){
        return;
    }
    //  recursiveCase
    int midIndex = (startIndex + endIndex)/2;
    mergeSort(a,startIndex,midIndex);
    mergeSort(a,midIndex+1,endIndex);
    return merge(a,startIndex,endIndex);
}
int main(){
    vector<int> arr{10,5,2,0,7,6,4};
    int start = 0;
    int end = arr.size()-1;
    mergeSort(arr,start,end);
    for(int element : arr)
        cout<<element<<",";
    cout<<endl;
    return 0;    
}
/*  selection Sort : Sorting all the elements by finding the min element index and swap at end of each pass by using index value
    Ex: If we have 5 elements like {8,5,7,3,2}, then we can do the trace like
    1. Just like bubble sort, start with n-1 pass as elements need n-1 comparision only
    2. Consider the first element index as min value.
    3. Check whether the min index value is greater than current element value
    4. If true then update the min index as current element index
    5. Do it till the end of the pass
    6. Swap the current min index value to the current index of i
    7. As we are placing the min value at top we can omit the top index next time by using j=i in inner loop
*/  
#include<iostream>
using namespace std;

void selectionSort(int *a,int size){
    int i,j,temp,minIndex; 
    for(i=0;i<size-1;i++)
    {
        minIndex = i;   // we need to consider,minimum index value is a[0], so index is 0. Next time onwards i value will be updated as we already copied the low value in i position
        for(j=i;j<size;j++)
        {
            if(a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
            temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
    }
}

int main(){
   int arr[]={6,-7,45,2,3,88,0,1};
   selectionSort(arr,8);
   for(int elements:arr){
        cout<<elements<<" ";
   }
   cout<<endl;
   return 0;
}




