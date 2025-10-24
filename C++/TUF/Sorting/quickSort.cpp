/*  quick Sort : Its a divide and conquer algorithm, where we will selelt the pivot element and try to keep the elements less than pivot on left side and greater than pivot on right side until all the elements are sorted 
*/
#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &a, int low, int high){
    int pivot = a[low];
    int i = low;
    int j = high;

    while(i < j){
        while(a[i] <= pivot && i <= high - 1) {
            i++;
        }
        while(a[j] > pivot && j >= low + 1) {
            j--;
        }
        if( i < j)  swap(a[i],a[j]);
    }
    swap(a[low], a[j]);
    return j;
}

void quickSort(vector<int> &a, int low, int high) {
    if(low < high) {
        int pIndex = partition(a, low, high);
        quickSort(a, low, pIndex - 1);
        quickSort(a, pIndex + 1, high);
    }
}
int main(){
    vector<int> arr{10,5,2,0,7,6,4};
    int start = 0;
    int end = arr.size()-1;
    quickSort(arr,start,end);
    for(int element : arr)
        cout<<element<<",";
    cout<<endl;
    return 0;    
}