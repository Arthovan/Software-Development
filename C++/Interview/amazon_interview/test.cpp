/*
Write a function to find and return the intersection of two arrays of integers.  
Example { 1, 7, 3, 10, 16 } and { 10, 5, 3, 12 } would give something like { 3, 10 }  
The function should handle arrays of any size.

{ 1, 2, 3, 4, 5 } and { 2, 2, 2, 2 }  give { 2 }

{ 7, 5, 7, 10, 7 } and { 3, 7, 14, 7 } gives { 7, 7 }

*/
#include<vector>
#include<unordered_map>
#include<iostream>

using namespace std;

vector<int> common_val(vector<int> x, vector<int> y){
    unordered_map<int,int> out_x;
    unordered_map<int,int> out_y;
    vector<int> temp;
    int i = 0, j = 0;
   /* while(i < x.size() and j < y.size()){
        if(out.find(x[i]) != out.end()){
            out.insert(x[i]);
            out.x[i]++;
        }
        if(out.find(y[i]) != out.end()){
            out.insert(y[i]);
            out.y[i]++;
        }
        i++;
        j++;
    }*/
    while(i < x.size()){
        if(out_x.find(x[i]) != out_x.end()){
            out_x.x[i]++; // 
        }
        else{
            out_x.insert(x[i]);
        }
        i++;
    }
    while(j < y.size()){
        if(out_y.find(y[j]) != out_y.end()){
            out_y.y[j]++;
        }
        else{
            out_y.insert(y[j]);
        }
        j++;
    }
    for(int [key,value]:out){
        if(value > 1){
            if()
            temp.push_back(key);
        }
    }
    return temp;
}
int main(){
    vector<int> a{1,7,3,10,16};
    vector<int> b{10,5,3,12};
    
    vector<int> temp = common_val(a,b);
    return 0;    
}

