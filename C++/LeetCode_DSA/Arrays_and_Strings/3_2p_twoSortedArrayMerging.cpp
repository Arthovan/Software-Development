/*  Example 3: Given two sorted integer arrays arr1 and arr2, return a new array that combines both of them and is also sorted.
    Time Complexity : O(n)
    Space Complexity : O(1)
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> mergeSortTwoArray(vector<int> a, vector<int> b){
    int i=0,j=0;
    vector<int> temp;
    while(i < a.size() and  j < b.size()){
        if(a[i] < b[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
            temp.push_back(b[j]);
            j++;
        }
    }
    while(i < a.size()){
        temp.push_back(a[i]);
        i++;
    }
    while(j < b.size()){
        temp.push_back(b[j]);
        j++;
    }
    return temp;
}

int main(){
    vector<int> arr{1,2,6,7};
    vector<int> brr{3,4,5,8,9};
    vector<int> temp;
    temp = mergeSortTwoArray(arr, brr);
    cout<<"After Merging : ";
    for(int n : temp)
        cout<<n<<",";
    cout<<endl;
    return 0;
}
