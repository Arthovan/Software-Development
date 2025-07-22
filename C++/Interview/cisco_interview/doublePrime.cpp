// Find the prime numbers from 1 to K and insert in the 2D array as double prime values
// Ex: prime from 1 to 10 is 2,3,5,7
// O/P : [3,5],[5,7]  == > double prime means differnce between adjacent prime is 2 

#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<vector<int>> prime(int data){
    vector<int> temp;
    vector<vector<int>> res;
    int cnt = 0;
    //temp.push_back(2);
    for(int i = 2; i<=data;i++)
    {   
        cnt = 0;
        for(int j = 2; j<i;j++){
            if(i%j == 0)
                cnt++;
        }
        if(cnt == 0){
            temp.push_back(i);
        }
    }

    for(auto ele : temp){
        cout<<ele<< " ";
    }

    int iterate = 0;
    for(int i = 0; i < (temp.size())-1;i++){
        int diff = temp[i+1] - temp[i];
        if(diff == 2)
        {
            res[iterate][0] = temp[i];
            res[iterate][1] = temp[i+1];
            i++;
            iterate++;
        }
    } 

    return res;
}

int main(){
   int val = 50; // 101
   vector<vector<int>> temp = prime(val);
   int len = temp.size()-1;
   for(vector<int> val: temp)
   {
    cout<<val[0]<<" "<<val[1];
   }
   cout<<endl;
   return 0;
}