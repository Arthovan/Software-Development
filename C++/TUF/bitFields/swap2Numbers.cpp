#include <iostream>
#include <vector>
using namespace std;

void swap2Numbers(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
int main(int argc, char* argv[]) {
    int a = 12;
    int b = 4;
    swap2Numbers(a,b);
    cout<<"After Swap a : "<<a<<" b : "<<b<<endl;
    return 0;
}