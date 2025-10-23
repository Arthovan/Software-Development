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
