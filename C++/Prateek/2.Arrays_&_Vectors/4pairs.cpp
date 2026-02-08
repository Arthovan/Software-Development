/*  Given an array containing N integers, and an number S denoting a target sum.
    Find two distinct integers that can pair up to form target sum. Let us assume there will be only one such pair.
*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//  As it has 2 for loops nested together its time complexity is O(n^2)
void bruteForce(vector<int> arr,int size,int number){

    //  for loop only
    /*for(int i = 0;i<size;i++){
        for(int j = i+1;j<size;j++){
            if((arr[i]+arr[j]) == number){
                cout<<arr[i]<<","<<arr[j]<<endl;
            }
        }
    }*/

    //  for each loop
    for(int i = 0;i<size;i++){
        for(int element:arr){
            if((arr[i]+element) == number){
                cout<<arr[i]<<","<<element<<endl;
            }
        }
    }
}

// using set establishing the pairs (Google Question)
vector<int> pairSum(vector<int> a,int target){
    vector<int> result;
    unordered_set<int> set;
    for(int i=0;i<a.size();i++){
        int difference = target - a[i];
        if(set.find(difference) != set.end()){
            result.push_back(difference);
            result.push_back(a[i]);
            return result;
        }
        set.insert(a[i]);
    }
    return result;
}

int main(){
    vector<int> a{10,5,2,3,-6,9,11};
    int S = 4;
    int len = sizeof(a)/sizeof(a[0]);
    bruteForce(a,len,S);
    pairSum(a,S);
    return 0;
}