#include<iostream>
#include<vector>

using namespace std;

void twoPointers(vector<int>a,int len,int k){
    int i = 0, j = 0,sum = 0;
        while(j < len){
            //Expand to the right
            sum += a[j];
            j++;

            // Remove the elements to the left is sum > k and i<j
            while(sum > k and i < j){
                sum -= a[i];
                i++;
            }

            if(sum == k){
                // print that window
                cout<<"["<<i<<" "<<j-1<<"]";    // j-1 because j incremented after the sum "expand to the right"
            }
        }
        cout<<endl;
}

int main(){
    vector<int> arr{1,3,2,1,4,1,3,2,1,1};
    twoPointers(arr, arr.size(),8);
    return 0;
}