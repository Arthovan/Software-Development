/*  Insertion sort : inserting the elements by comparing its value to every elements and insert in the correct place of sorted order
    Time complexity O(1) - O(n^2) -> Because of shifting an elements, if at 1st place then O(1), if not O(n^2)
    Space complexity O(1) 
    Insertion sort is designed for linked list and in array its convenient
    Adaptive : Yes minimum time required to swap elements is O(n)
Comparision of Bubble Sort and Insertion Sort
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
	
	// Easy method to remember
	for(int i = 0; i < n; ++i) {
		int j = i; 
		while (j > 0 and arr[j-1] > arr[j]) {
			swap(arr[j-1], arr[j]);
			j--;
		}
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
