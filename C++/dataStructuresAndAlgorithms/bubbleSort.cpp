/*  Bubble Sort : Sorting all the elements by comparing against each other and swap it
    Ex: If we have 5 elements like {8,5,7,3,2}, then we can do the trace like
     Pass1      Pass2     Pass3     Pass4         
    5 5 5 5     5 5 5      3 3       2
    8 7 7 7     7 3 3      5 2       3
    7 8 3 3     3 7 2      2 5       5
    3 3 8 2     2 2 7      7 7       7
    2 2 2 8     8 8 8      8 8       8
    As we can clearly see that at the end of each pass maximum elements are sorted out also, 
    number of loops also reduced 
    So we have to traverse n-1 times in outer loop and reduce the inner loop by i times
*/  
    #include<iostream>
using namespace std;

void bubbleSort(int *a,int size){
    int i,j,temp;

    for(i=0; i<size-1; i++){    
        for(j=0; j<size-1-i; j++){
            if(a[j]>a[j+1]){
            temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
            }
        }
    }
}

int main(){
   int arr[]={6,-7,45,2,3,88,0,1};
   bubbleSort(arr,8);
   for(int elements:arr){
        cout<<elements<<" ";
   }
   cout<<endl;
   return 0;
}