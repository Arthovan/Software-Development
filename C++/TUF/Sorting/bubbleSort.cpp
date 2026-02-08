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

    Time complexity O(n) - O(n^2) -> Because of 2 loops, if already sorted then O(n), if not O(n^2)
    Space complexity O(1) 
    We can improve the bubble sort minimum iteration by using flag so that minimum time required
    to sort will be O(n) if already elements are in sorted order.
    Is it Adaptive : Adaptive means minimum time taken to sort the elements, and it minimum time is O(n). This we achieved by introducing flag.
*/  
    #include<iostream>
using namespace std;

void bubbleSort(int *a,int size){
    int i,j,temp,flag=0;

    for(i=0; i<size-1; i++){    //  for n elements we compare n-1 times so only size-1
        flag = 0;
        for(j=0; j<size-1-i; j++){    //  after every 1 inner forloop 1 element is sorted, next time 2, after that 3, so it follows i. So we have used size-1-i
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(flag == 0)   //  This means no sorting happened in the first loop and elements are already in the sorted order
            break;
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
