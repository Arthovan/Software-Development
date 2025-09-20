/*	234. Palindrome Linked List
Given the head of a singly linked list, return true if it is a palindrome or false otherwise. */

#include<iostream>
#include<vector>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node():data(0),next(nullptr){}
    Node(int x) : data(x), next(nullptr){}
    Node(int x, Node* next):data(x),next(next){}
};

void insertLL(Node *&headLL, int data) {
    if(headLL == NULL){
        headLL = new Node(data);
        return;
    }
    Node *temp = new Node(data);
    temp->next = headLL;
    headLL = temp;
}

void displayLL(Node* headLL) {
    while(headLL != NULL) {
        cout<< headLL->data<<"-->";
        headLL = headLL->next;
    }
    cout<<endl;
}
bool isPalindrome(Node* head) {
	vector<int> temp;
	int left = 0, right = 0;
	while(head!= NULL){
		temp.push_back(head->data);
		head = head->next;
	}
	right = temp.size() - 1;
	while(left < right) {
		if(temp[left] != temp[right]){
			return false;
		}
		left++;
		right--;      
	}
	return true;
}

int main(int argc, char*argv[]) {
    Node *head = NULL;
    vector<int> val{1,2,2,1};
    for(int i = 0; i < val.size(); i++) {
       insertLL(head,val[i]);
    }
    displayLL(head);
    cout<<"Vector palindrome validity is : "<<isPalindrome(head)<<endl; 
    return 0;
}