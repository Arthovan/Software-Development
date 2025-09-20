#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> collide;
    vector<int> out;
    bool destroyed = false;

    for(auto val : asteroids) {
        destroyed = false;
        while(!collide.empty() and collide.top() > 0 and val < 0 ) {
            if(collide.top() < abs(val)) {
                collide.pop();
                continue;
            }
            else if(collide.top() == abs(val)) {
                collide.pop();
            }
            destroyed = true;
            break;
        }

        if(!destroyed) {
            collide.push(val);
        }
    }
    while(!collide.empty()) {
        //cout<<collide.top()<<endl;
        out.push_back(collide.top());
        collide.pop();
    }
    reverse(out.begin(),out.end());
    return out;
}

int main(int argc, char* argv[]) {
    vector<int> asteroi{-2,1,-1,-2};
    vector<int> temp = asteroidCollision(asteroi);
    if(!temp.empty()) {
        cout<<"Output is : ";
        for(auto val : temp) {
            cout<<val<<" ";
        }
        cout<<endl;
    } else {
        cout<<"Value is empty"<<endl;
    }
    return 0;
}