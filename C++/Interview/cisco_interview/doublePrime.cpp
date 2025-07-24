// Find prime numbers up to a given number K and then identify pairs of "double primes"(pair of primes that differ by 2).

#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<vector<int>> prime(int data){
    vector<int> temp;
    vector<vector<int>> res;
    //vector<pair<int, int>> pair;
    int cnt = 0;
    // find all prime numbers upto data
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
    // find double primes
    for(int i = 0; i < (temp.size())-1;i++){
        if((temp[i+1] - temp[i]) == 2)
        {
            res.push_back({temp[i],temp[i+1]});
            //res[0].push_bakc(temp[i]);
            //res[1].push_bakc(temp[i+1]);
        }
    } 
    return res;
}

int main(){
   int val = 50; 
   vector<vector<int>> temp = prime(val);
   for(vector<int> val: temp)
   {
    cout<<"["<<val[0]<<", "<<val[1]<<"] ";
   }
   cout<<endl;
   return 0;
}
