#include <iostream>
#include <vector>

using namespace std;

struct LinkedListNode {
    int val;
    LinkedListNode *next;
    // Struct in C++ can have constructor, by default all the members are public but in class by default it is private.
    LinkedListNode(int val):val(val),next(nullptr) {}
};
int main(int argc, char*argv[]) {
    LinkedListNode *one = new LinkedListNode(1);
    LinkedListNode *two = new LinkedListNode(2);
    LinkedListNode *three = new LinkedListNode(3);

    one->next = two;
    two->next = three;
    LinkedListNode *head = one;

    cout<< head->val << endl;
    cout<< head->next->val << endl;
    cout<< head->next->next->val << endl;

    return 0;
}