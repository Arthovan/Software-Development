/* 605. Can Place Flowers

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

Example 1:  Input: flowerbed = [1,0,0,0,1], n = 1   Output: true
Example 2:  Input: flowerbed = [1,0,0,0,1], n = 2   Output: false  */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    for(int i = 0; i < flowerbed.size(); i++) {
        if(flowerbed[i] == 0) {
            bool leftPlot = (i == 0) || (flowerbed[i - 1] == 0);
            bool rightPlot = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);

            if(leftPlot and rightPlot) {
                flowerbed[i] = 1;
                count++;
                if(count >= n){
                    return true;
                }
            }
        }
    }
    return count >= n;
}

int main(int argc, char*argv[]) {
    vector<int> val{1,0,0,0,1};
    int n = 1;
    cout<<"Can place flowers output is : "<<canPlaceFlowers(val,n)<<endl;
    return 0;
}