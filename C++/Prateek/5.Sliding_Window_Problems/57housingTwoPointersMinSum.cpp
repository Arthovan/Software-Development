#include<iostream>
#include<vector>

using namespace std;

void twoPointers(vector<int>a,int len,int k){
    int i = 0, j = 0,sum = 0, smallSum = len, temp[2];
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
                if(smallSum > ((right-1)-left)){
                    temp[0] = left;
                    temp[1] = right-1;
                    smallSum = (right-1)-left;
                }
            }
        }
        cout<<endl;
        cout<<"small index: "<<"["<<temp[0]<<" "<<temp[1]<<"]";
        cout<<endl;
}

int main(){
    vector<int> arr{1,3,2,1,4,1,3,2,1,1};
    twoPointers(arr, arr.size(),8);
    return 0;
}
