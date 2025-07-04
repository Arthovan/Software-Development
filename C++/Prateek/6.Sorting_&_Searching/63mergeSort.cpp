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