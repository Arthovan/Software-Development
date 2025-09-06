#include<iostream>
#include<vector>
#include<climits>

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

int pairSum(Node* head) {
    // Edge case where node is NULL
    if(head == NULL){
        return 0;
    }
    Node *dummy = head;
    vector<int> temp;
    // Store the data alone in vector for ease of traverse
    while(dummy != NULL){
        temp.push_back(dummy->data);
        dummy = dummy->next;
    }
    int left = 0;
    int right = temp.size()-1;
    int maxVal = INT_MIN;
    while(left < right){
        int data = temp[left]+temp[right];
        maxVal = max(data,maxVal);
        left++;
        right--;
    }
    return maxVal;
}

int main(int argc, char*argv[]) {
    Node *head = NULL;
    vector<int> temp{5,4,2,10};
    for(int i = 0; i < temp.size(); i++) {
        insertLL(head, temp[i]);
    }
    cout<<"Maximum Pair Sum : "<<pairSum(head)<<endl;    
    return 0;
}
