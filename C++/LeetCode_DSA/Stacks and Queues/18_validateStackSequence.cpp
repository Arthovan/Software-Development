#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int i = 0;
    
    for(auto val : pushed) {
        //cout<<"Val: "<<val<<endl;
        st.push(val);       //  we keep on push the value of pushed into the stack st 
        while(!st.empty() and st.top() == popped[i]) {  // when this condition meets then we can pop the matching elements
            //cout<<"st.top(): "<<st.top()<<endl;
            st.pop();
            i++;
        }
    }
    return st.empty();  // if all the elements are popped then we know that it it valid sequence
}

int main(int argc, char* argv[]) {
    vector<int> pushed{1,2,3,4,5}, popped{4,5,3,2,1};
    cout<<"Validity of Stack Sequence is : "<<validateStackSequences(pushed,popped)<<endl;
    return 0;
}
////////////////////////////