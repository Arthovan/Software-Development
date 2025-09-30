#include<iostream>
#include<vector>

using namespace std;

void twoPointers(vector<int>a,int len,int k){
    int left = 0, right = 0,sum = 0;
        while(right < len){
            //Expand to the right
            sum += a[right];
            right++;

            // Remove the elements to the left is sum > k and i<j
            while(sum > k and left < right){
                sum -= a[left];
                left++;
            }

            if(sum == k){
                // print that window
                cout<<"["<<left<<" "<<right-1<<"]";    // right-1 because right incremented after the sum "expand to the right"
            }
        }
        cout<<endl;
}

int main(){
    vector<int> arr{1,3,2,1,4,1,3,2,1,1};
    twoPointers(arr, arr.size(),8);
    return 0;
}
