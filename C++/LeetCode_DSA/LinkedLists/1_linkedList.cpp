#include <iostream>
#include <vector>

using namespace std;

struct LinkedListNode {
    int val;
    LinkedListNode *next;
    // Struct in C++ can have constructor, by default all the members are public but in class by default it is private.
    LinkedListNode(int val):val(val),next(nullptr) {}
};
// Get the sum of the elements in the LinkedLists
int getSum(LinkedListNode *head) {
    int ans = 0;
    while(head != NULL) { 
        ans += head->val;
        head = head->next;
    }
    return ans;
}
// Get the sum of the elements in recurssive way
int recSum(LinkedListNode *head) {
    if(head == NULL) { 
        return 0;
    }
    return head->val + recSum(head->next);
}
int main(int argc, char*argv[]) {
    LinkedListNode *one = new LinkedListNode(1);
    LinkedListNode *two = new LinkedListNode(2);
    LinkedListNode *three = new LinkedListNode(3);

    one->next = two;
    two->next = three;
    LinkedListNode *head = one;

    cout<<"Node One : "<< head->val << endl;
    cout<<"Node Two : "<< head->next->val << endl;
    cout<<"Node Three: "<< head->next->next->val << endl;

    cout<<"Sum : "<< getSum(head)<< endl;
    cout<<"Recursive Sum : "<< recSum(head)<< endl;

    return 0;
}