3sort.txt

/*  Inbuilt Sort Function

    Some problems may require the use of a sorting algorithm, and I hope you are already familiar with basic sorting algorithms like Bubble Sort, Selection Sort, Insertion Sort which have O(n^2) complexity. 
    Better algorithms include Merge Sort, Quick Sort and Heap Sort which have O(nLogn) complexity. For most array problems we can use the inbuilt sort function which also offers O(nlogn) complexity. 
    This is how you can use the inbuilt sort function in case you are not aware of. Also depending upon the data in the problem, you may also require Counting Sort, or Bucket Sort or Radix Sort sometimes.
    Ex: Sort an array containing N integers
        sort(arr, arr +n)
    Ex: Sort an vector containing N integers
        sort(arr.begin(), arr.end())    
        
    Some useful links : Hashing Problems    https://youtu.be/UJkE-apV9Dk
                        Space Time Complexity:  https://youtu.be/PbnRLSAYkRo    */
						
4pairs.cpp

/*  Given an array containing N integers, and an number S denoting a target sum.
    Find two distinct integers that can pair up to form target sum. Let us assume there will be only one such pair.
*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//  As it has 2 for loops nested together its time complexity is O(n^2)
void bruteForce(vector<int> arr,int size,int number){

    //  for loop only
    /*for(int i = 0;i<size;i++){
        for(int j = i+1;j<size;j++){
            if((arr[i]+arr[j]) == number){
                cout<<arr[i]<<","<<arr[j]<<endl;
            }
        }
    }*/

    //  for each loop
    for(int i = 0;i<size;i++){
        for(int element:arr){
            if((arr[i]+element) == number){
                cout<<arr[i]<<","<<element<<endl;
            }
        }
    }
}

// using set establishing the pairs
vector<int> pairSum(vector<int> a,int tar){
    vector<int> result;
    unordered_set<int> se;
    for(int i=0;i<a.size();i++){
        int x = tar - a[i];
        if(se.find(x) != se.end()){
            result.push_back(x);
            result.push_back(a[i]);
            return result;
        }
        se.insert(a[i]);
    }
    return result;
}

vector<int> pairSum(vector<int> arr, int S){
    ;;

}
int main(){
    vector<int> a{10,5,2,3,-6,9,11};
    int S = 4;
    int len = sizeof(a)/sizeof(a[0]);
    bruteForce(a,len,S);
    return 0;
}

43bitWiseOddEven.cpp

#include<iostream>

using namespace std;

int main(){
    int val;
    cout<<"Enter the input value: ";
    cin>>val;
    if(val&1)
        cout<<"Odd"<<endl;
    else
        cout<<"Even"<<endl;
}

44bitWiseGetBit.cpp

#include<iostream>

using namespace std;

void getBit(int value, int bitValue){
    int mask = 1<<bitValue;
    if((value & mask))
        cout<<"Bit Values is : 1"<<endl;
    else
        cout<<"Bit Values is : 0"<<endl;
}

int main(){
    int val,bitPosition;
    cout<<"Enter the input value: ";
    cin>>val;
    cout<<"Enter the bit position to get value: ";
    cin>>bitPosition;
    getBit(val,bitPosition);
    return 0;
}

45bitWiseSetBit.cpp
#include<iostream>

using namespace std;

void setBit(int value, int bitValue){
    int mask = 1<<bitValue;
    value |= mask;
    
    cout<<"After set, value now is: "<<value<<endl;
}

int main(){
    int val,bitPosition;
    cout<<"Enter the input value: ";
    cin>>val;
    cout<<"Enter the set bit position to set value: ";
    cin>>bitPosition;
    setBit(val,bitPosition);
    return 0;
}

46bitWiseClearBit.cpp
#include<iostream>

using namespace std;

void clearBit(int value, int bitValue){
    int mask = ~(1<<bitValue);
    value &= mask;
    
    cout<<"After clear, value now is: "<<value<<endl;
}

int main(){
    int val,bitPosition;
    cout<<"Enter the input value: ";
    cin>>val;
    cout<<"Enter the bit position to clear: ";
    cin>>bitPosition;
    clearBit(val,bitPosition);
    return 0;
}

47bitWiseUpdateBit.cpp

#include<iostream>

using namespace std;

int clearBit(int value, int bitPos){
    int mask = ~(1<<bitPos);
    value &= mask;
    return value;
}

void updateBit(int value, int bitPos,bool bitValue){
    value = clearBit(value,bitPos);
    int mask = (bitValue<<bitPos);
    value |= mask;
    
    cout<<"After update, value now is: "<<value<<endl;
}

int main(){
    int val,bitPosition;
    bool bitValue;
    cout<<"Enter the input value: ";
    cin>>val;
    cout<<"Enter the bit position to update: ";
    cin>>bitPosition;
    cout<<"Enter the bit value either 0 or 1: ";
    cin>>bitValue;
    updateBit(val,bitPosition,bitValue);
    return 0;
}

48bitWiseClearLastNBits.cpp

#include<iostream>

using namespace std;

void clearLastNBits(int value, int bitPos){
    int mask = (-1<<bitPos);
    value &= mask;
    cout<<"After clear N bits, value now is: "<<value<<endl;
}

int main(){
    int val,bitPosition;
    bool bitValue;
    cout<<"Enter the input value: ";
    cin>>val;
    cout<<"Enter the bit position to clear from last: ";
    cin>>bitPosition;
    clearLastNBits(val,bitPosition);
    return 0;
}

49bitWiseReplaceBitChallenge.cpp

#include<iostream>

using namespace std;

/*  Replace bits in N by M
    You are given two 32-bit numbers, N and M, two bit positions i and j.
    write a method to set all bits between i and j in N equal to M.
    M (becomes a substring of N locationed at and starting at j)
    Example:
    N = 10000000000;
    M = 10101;
    i =2, j = 6
    Output : 1001010100
*/
void clearBitsInRange(int &M, int i, int j){    // j is 3 for our case, j+1 is 4 times shifting
    int a = (-1)<<(j+1);    //  1111 1111 << (j+1)  ===> 1111 0000
    int b = (1<<i)-1;       // i is 2,  and I should have value 1 in all bits before i so shifting 1 inot i times and minus 1 will give us the result. Ex: 1 << 3 times is 8 and it is 1000, 8-1 is 7 so it is 0111. Thereby I can have 1 before i elements
    int mask = a | b;
    M = M & mask;
}
void replaceBitsInRange(int &m, int n, int i, int j){
    clearBitsInRange(m, i, j);
    int mask = n << i;
    m = m | mask;
}
int main(){
    int M = 15;
    int N = 2;
    int i = 1, j = 3;
    replaceBitsInRange(M, N, i, j);
    cout<<"After replacing the value of M: "<<M<<endl;
    return 0;
}

50bitWisePowerOfTwo.cpp

/* Only for power of 2 alone , if we multiply the given number n with (n-1) the answer is zero then we can say its a power of 2. Note it wont work for other powers remember that
    Ex: 2^3 = 8. Lets check check 8 is power of 2
    n       =>8     =   0000 1000
    n-1     =>7     =   0000 0111
                        ----------
    n & (n-1)       =   0000 0000 
                        -----------                    
*/

#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    if((n&(n-1) )== 0)
        cout<<"Power of 2"<<endl;
    else
        cout<<"Not a power of 2"<<endl;
    return 0;
}

51bitWiseCoutnSetBits.cpp

/* We can use the same strategy as power of 2 here,  N * (N - 1), 
    Ex: Number of set bits in 7
    Step 1: increment the counter 
    Step 2: do this operation
        n       =>7     =   0000 0111
        n-1     =>6     =   0000 0110
                            ----------
        n & (n-1)       =   0000 0110 
                            -----------
    Step 3: repeat step 1 until n becomes zero, in every n * n-1 we can get 1 set bit out of the n there we can spend less number of iterations compared to brute force
*/
#include<iostream>

using namespace std;

// Brute force method, where complexity is always O(n), as it has to traverse all the bits on n even if it has zero values
// Lets say 0x01 and its binary is 0000 0001, its for 8 bit values and to check the number of set bits, it has to iterate 8 times
void bfCountSetBits(int n){
    int count = 0;
    while(n>0){
        if(n&1)
            count++;
        n = n >>1;
    }
    cout<<"Count bits via Brute Force is : "<<count<<endl;

}
// Efficient method of n*(n-1), where minimum complexity is always O(1) and maximum complexity is O(n) , as it has to traverse only if it has valid ones
// Lets say 0x01 and its binary is 0000 0001, its for 8 bit values and to check the number of set bits, it has to iterate 1 times
// Worst case scenario is 1111 1111, where it has to iterate 8 times to get the number of set bits
void countSetBits(int n){
    int count = 0;
    while(n>0){
        count++;
        //  Removes the last set bit from the current number
        n = n & (n-1);
    }
    cout<<"Count bits via N*(N-1) is : "<<count<<endl;
}

int main(){
    int n;
    cout<<"Enter the number to count its set bits: ";
    cin>>n;
    cout<<"Brute Force Method"<<endl;
    bfCountSetBits(n);
    cout<<"N&N-1 method"<<endl;
    countSetBits(n);
    return 0;
}

53bitWiseFastExponentiation.cpp

/* Fast Exponentiation :     Lets say a =3 and power is 5 => 3^5 is the input and convert it as 3^(101), where 101 is the binary representation of 5
                        Where we need to start a "count" variable with an initial value as 1
                        during 1st iteration, if first bit value valid, multiply "count" variable with 3, else do nothing. Then multiply a =a*a, shift n one time 
                        during 2nd iteration, if second bit value valid, multiply "count" variable with 3, else do nothing. Then multiply a =a*a, shift n one time 
                        during 3rd iteration, if third bit value valid, multiply "count" variable with 3, else do nothing. Then multiply a =a*a, shift n one time 

                        Complexity is O(logn)
*/
#include<iostream>

using namespace std;

int fastExponentiation(int num, int power){
    int count = 1;
    while(power > 0){
        int lastBit = power & 1;
        if(lastBit){
            count *= num;
        }
        num = num * num;
        power = power >> 1;
    }
    return count;
}

int main(){
    int number,power,temp;
    cout<<"Enter the number to do the exponent: ";
    cin>>number;
    cout<<"Enter the power: ";
    cin>>power;
    temp = fastExponentiation(number, power);
    cout<<number<<"^"<<power<<" is "<<temp<<endl;
    return 0;
}

54bitWiseDecimalToBinary.cpp
/*  Convert a number from decimal format into binary format.
    Example :
        Input   : N = 10
        Output  : 1010
*/    
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int num, rem, len;
    vector<int> out;

    cout<<"Enter the number to convert into binary: ";
    cin>>num;
    while(num > 0){
        rem = num & 1;
        out.push_back(rem);
        num = num >> 1;        
    }
    len = out.size();
    for(int i=len-1;i>=0;i--)
        cout<<out[i]<<" ";
    cout<<endl;
    return 0;
}

57housingTwoPointers.cpp

#include<iostream>
#include<vector>

using namespace std;

void twoPointers(vector<int>a,int len,int k){
    int i = 0, j = 0,sum = 0;
        while(j < len){
            //Expand to the right
            sum += a[j];
            j++;

            // Remove the elements to the left is sum > k and i<j
            while(sum > k and i < j){
                sum -= a[i];
                i++;
            }

            if(sum == k){
                // print that window
                cout<<"["<<i<<" "<<j-1<<"]";    // j-1 because j incremented after the sum "expand to the right"
            }
        }
        cout<<endl;
}

int main(){
    vector<int> arr{1,3,2,1,4,1,3,2,1,1};
    twoPointers(arr, arr.size(),8);
    return 0;
}

57housingTwoPointersMinSum.cpp

#include<iostream>
#include<vector>

using namespace std;

void twoPointers(vector<int>a,int len,int k){
    int i = 0, j = 0,sum = 0, smallSum = len, temp[2];
        while(j < len){
            //Expand to the right
            sum += a[j];
            j++;

            // Remove the elements to the left is sum > k and i<j
            while(sum > k and i < j){
                sum -= a[i];
                i++;
            }

            if(sum == k){
                // print that window
                cout<<"["<<i<<" "<<j-1<<"]";    // j-1 because j incremented after the sum "expand to the right"
                if(smallSum > ((j-1)-i)){
                    temp[0] = i;
                    temp[1] = j-1;
                    smallSum = (j-1)-i;
                }
            }
        }
        cout<<endl;
        cout<<"small index: "<<"["<<temp[0]<<" "<<temp[1]<<"]";
        cout<<endl;
}

int main(){
    vector<int> arr{1,3,2,1,4,1,3,2,1,1};
    twoPointers(arr, arr.size(),8);
    return 0;
}

63mergeSort.cpp

/*  Merge Sort : Its a divide and conquer algorithm, input array is divided into 2 parts, where both the parts will split into again and again until one element is there 
    then the sorting will happen.
*/
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &a, int startIndex, int endIndex){
    int i = startIndex;
    int midIndex = (startIndex + endIndex)/2;
    int j = midIndex + 1;
    vector<int> temp;

    while(i <= midIndex and j <= endIndex){
        if(a[i] < a[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
            temp.push_back(a[j]);
            j++;
        }
    }
    //  copy remaining elements from first array
    while(i <= midIndex){
        temp.push_back(a[i++]);
    }
    //  copy remaining elements from second array
    while(j <= endIndex){
        temp.push_back(a[j++]);
    }
    //  copy back the elements from temp to original array
    int k = 0;
    for(int idx = startIndex; idx <= endIndex; idx++){
        a[idx] = temp[k++];
    }
    return;
}

void mergeSort(vector<int> &a,int startIndex, int endIndex){
    //  baseCase --> if array has 0 0r 1 element then no need to sort
    if(startIndex >= endIndex){
        return;
    }
    //  recursiveCase
    int midIndex = (startIndex + endIndex)/2;
    mergeSort(a,startIndex,midIndex);
    mergeSort(a,midIndex+1,endIndex);
    return merge(a,startIndex,endIndex);
}
int main(){
    vector<int> arr{10,5,2,0,7,6,4};
    int start = 0;
    int end = arr.size()-1;
    mergeSort(arr,start,end);
    for(int element : arr)
        cout<<element<<",";
    cout<<endl;
    return 0;    
}

106createLL.cpp

#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

// Method to insert element at the head with the refernce method
void insertAtHead(Node * &headLL, int data){
    // if node is empty and we need to insert an element
    if(headLL == NULL){
        headLL = new Node(data);
        return;
    }

    // if node is not empty and we need to insert an element at head
    Node *temp = new Node(data);
    temp->next = headLL;
    headLL = temp;
}

// Display the entire LL elements 
void displayLL(Node *headDisplayLL){
    while(headDisplayLL != NULL){
        cout<<headDisplayLL->data<<"-->";
        headDisplayLL = headDisplayLL->next;
    }
    cout<<endl;
}

int main(){
    Node *head = NULL;
    vector<int> arr{2,-7,4,5,8,0};
    for(int i=0;i<arr.size();i++)
        insertAtHead(head,arr[i]);
    displayLL(head);
    return 0;
}

107insertLLInMiddle.cpp

#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

// Method to insert element at the head with the refernce method
void insertAtHead(Node* &headLL, int data){
    // if node is empty and we need to insert an element
    if(headLL == NULL){
        headLL = new Node(data);
        return;
    }   

    // if node is not empty and we need to insert an element at head  
    Node *temp = new Node(data);
    temp->next = headLL;
    headLL = temp;  
}

// Insert data at the specific position
void insertInMiddle(Node* &headMLL, int pos, int data){
    if(pos==0){
        insertAtHead(headMLL,data);
    }
    else{
        Node *localMLL = headMLL;
        for(int jump=0;jump<pos;jump++){
            localMLL =localMLL->next;
        }
        Node *temp = new Node(data);
        temp->next = localMLL->next;
        localMLL->next = temp;
    }
}

// Display the entire LL elements 
void displayLL(Node *headDisplayLL){
    while(headDisplayLL != NULL){
        cout<<headDisplayLL->data<<"-->";
        headDisplayLL = headDisplayLL->next;
    }
    cout<<endl;   
}

int main(){
    Node *head = NULL;
    vector<int> arr{2,-7,4,5,8,0};
    for(int i=0;i<arr.size();i++)
        insertAtHead(head,arr[i]);
    displayLL(head);

    insertInMiddle(head,5,12);
    displayLL(head);
    
    insertInMiddle(head,0,6);
    displayLL(head);
    return 0;
}

108reverseLlRecursive.cpp

#include <cstddef>
#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

// Method to insert element at the head with the refernce method
void insertAtHead(Node* &headLL, int data){
    // if node is empty and we need to insert an element
    if(headLL == NULL){
        headLL = new Node(data);
        return;
    }   

    // if node is not empty and we need to insert an element at head  
    Node *temp = new Node(data);
    temp->next = headLL;
    headLL = temp;  
}

// Insert data at the specific position
void insertInMiddle(Node* &headMLL, int pos, int data){
    if(pos==0){
        insertAtHead(headMLL,data);
    }
    else{
        Node *localMLL = headMLL;
        for(int jump=0;jump<pos;jump++){
            localMLL =localMLL->next;
        }
        Node *temp = new Node(data);
        temp->next = localMLL->next;
        localMLL->next = temp;
    }
}

//  Reverse the links alone not the data
Node* reverseLLRecursive(Node* head){
    // Base case: if head is null or only one node, return head
    if(head == NULL or head->next == NULL)
        return head;
    // Recursive case: reverse the rest of the list
    Node *sHead = reverseLLRecursive(head->next);

    // Adjust the pointers
    head->next->next = head;    // Make the next node point to the current node
    head->next = NULL;          // Set the current node's next to null  
    return sHead;               // Return the new head of the reversed list, this is always last element node bcs its the new head after link reversal
}

// Display the entire LL elements 
void displayLL(Node *headDisplayLL){
    while(headDisplayLL != NULL){
        cout<<headDisplayLL->data<<"-->";
        headDisplayLL = headDisplayLL->next;
    }
    cout<<endl;   
}

int main(){
    Node *head = NULL;
    vector<int> arr{2,-7,4,5,8,0};
    for(int i=0;i<arr.size();i++)
        insertAtHead(head,arr[i]);
    cout<<"Insert at Head is done"<<endl;
    displayLL(head);

    cout<<"Insert at middle"<<endl;
    insertInMiddle(head,5,12);
    displayLL(head);
    
    cout<<"Insert at middle"<<endl;
    insertInMiddle(head,0,6);
    displayLL(head);

    cout<<"Reverse a LL recursively"<<endl;
    head = reverseLLRecursive(head);
    displayLL(head);

    return 0;
}

111reverseLlIterative.cpp

#include <cstddef>
#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

// Method to insert element at the head with the refernce method
void insertAtHead(Node* &headLL, int data){
    // if node is empty and we need to insert an element
    if(headLL == NULL){
        headLL = new Node(data);
        return;
    }   

    // if node is not empty and we need to insert an element at head  
    Node *temp = new Node(data);
    temp->next = headLL;
    headLL = temp;  
}

// Insert data at the specific position
void insertInMiddle(Node* &headMLL, int pos, int data){
    if(pos==0){
        insertAtHead(headMLL,data);
    }
    else{
        Node *localMLL = headMLL;
        for(int jump=1;jump<pos;jump++){
            localMLL =localMLL->next;
        }
        Node *temp = new Node(data);
        temp->next = localMLL->next;
        localMLL->next = temp;
    }
}

//  Reverse the links alone not the data
Node* reverseLLRecursive(Node* head){
    // Base case: if head is null or only one node, return head
    if(head == NULL or head->next == NULL)
        return head;
    // Recursive case: reverse the rest of the list
    Node *sHead = reverseLLRecursive(head->next);

    // Adjust the pointers
    head->next->next = head;    // Make the next node point to the current node
    head->next = NULL;          // Set the current node's next to null  
    return sHead;               // Return the new head of the reversed list, this is always last element node bcs its the new head after link reversal
}

void reverseLLIterative(Node* &head){
    Node* previousNode = NULL, *nextNode = NULL, *currentNode = head;
    while(currentNode != NULL){
        // Store the next node
        nextNode = currentNode->next;
        //Update the current node next 
        currentNode->next = previousNode;
        // Update previous and current node
        previousNode = currentNode;
        currentNode = nextNode;        
    }

    head = previousNode;    //  Because current node will have NULL and during while check only it fails so the previous node holds the current node data
}
// Display the entire LL elements 
void displayLL(Node *headDisplayLL){
    while(headDisplayLL != NULL){
        cout<<headDisplayLL->data<<"-->";
        headDisplayLL = headDisplayLL->next;
    }
    cout<<endl;   
}

int main(){
    Node *head = NULL;
    vector<int> arr{2,-7,4,5,8,0};
    for(int i=0;i<arr.size();i++)
        insertAtHead(head,arr[i]);
    cout<<"Insert at Head is done"<<endl;
    displayLL(head);

    cout<<"Insert at middle"<<endl;
    insertInMiddle(head,5,12);
    displayLL(head);
    
    cout<<"Insert at middle"<<endl;
    insertInMiddle(head,0,6);
    displayLL(head);

    cout<<"Reverse a LL Iteratively"<<endl;
    reverseLLIterative(head);
    displayLL(head);

    cout<<"Reverse a LL recursively"<<endl;
    head = reverseLLRecursive(head);
    displayLL(head);

    return 0;
}

115mergeTwoSorted.cpp

#include <cstddef>
#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

// Method to insert element at the head with the refernce method
void insertAtHead(Node* &headLL, int data){
    // if node is empty and we need to insert an element
    if(headLL == NULL){
        headLL = new Node(data);
        return;
    }   

    // if node is not empty and we need to insert an element at head  
    Node *temp = new Node(data);
    temp->next = headLL;
    headLL = temp;  
}

// Display the entire LL elements 
void displayLL(Node *headDisplayLL){
    while(headDisplayLL != NULL){
        cout<<headDisplayLL->data<<"-->";
        headDisplayLL = headDisplayLL->next;
    }
    cout<<endl;   
}

Node* mergeTwoSortedLL(Node *a, Node *b){
    // Base Case
    if(a == NULL)   return b;   //  If "a" LL is empty then only "b" data remains so return b
    if(b == NULL)   return a;   //  If "b" LL is empty then only "a" data remains so return a

    Node *c;
    if(a->data < b->data){  //  Comapre which LL data is small
        c = a;              //  Assign that LL head to temp node c
        c->next = mergeTwoSortedLL(a->next, b); //  temp head next is again the sorted call which will return the small data and merge call and so on 
    }
    else{
        c = b;
        c->next = mergeTwoSortedLL(a->next, b);
    }
    return c;
}

int main(){
    Node *head = NULL;
    Node *head1 = NULL;
    vector<int> arr{1,2,3,4};
    vector<int> brr{5,6,7};
    for(int i=0;i<arr.size();i++)
        insertAtHead(head,arr[i]);
    cout<<"Insert at Head is done for head"<<endl;

    for(int i=0;i<brr.size();i++)
        insertAtHead(head,brr[i]);
    cout<<"Insert at Head is done for head1"<<endl;

    head = mergeTwoSortedLL(head,head1);
    displayLL(head);



    return 0;
}

ce12_bitWiseEarthlevels.cpp

/*  Earth Levels
The Planet Earth is under a threat from the aliens of the outer space and your task is to defeat an enemy who is N steps above you (assume yourself to be at ground level i.e. at the 0th level). You can take jumps in power of 2. In order to defeat the enemy as quickly as possible you have to reach the Nth step in minimum moves possible.

Input Format : In the function an integer is passed.
Output Format : Return an integer representing minimum jumps.
Sample Input : 7
Sample Output : 3
Explanation : 0 -> 4 -> 6 -> 7
*/
#include<iostream>
using namespace std;

// This code is same as n * n -1 method ==>  count the number of set bits
int returnSteps(int k){
    int jump = 0;
    while(k > 0){
        jump++;
        k = k & (k-1);
    }
    return jump;
}

int main(int argc, char const *argv[])// Even without argc and argv this program works fine
{
    int n;
    cin>>n;
    cout<<returnSteps(n)<<endl;
    return 0;
}

ce30_searchKeyLL.cpp

#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;


class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next =NULL;
    }
};

// Created a insert method with return the head method and we can use here instance as well which we will see in the upcoming lectures
Node* insertAtHead(Node *headLL,int data){
    if(headLL == NULL){
        headLL = new Node(data);
        return headLL;
    }
    Node *temp = new Node(data);
    temp->next = headLL;
    headLL = temp;
    return headLL;  
}

// Checking whether the key is present in the linked list or not
bool isPresent(Node * head, int key){
    //Complete this function 
    Node *temp = head;
    while(temp != NULL){
        if(key == temp->data)
            return true;
        temp=temp->next;
    }
    return false;
}

int main(){
    vector<int> arr{2,-7,4,5,8,0};
    Node *head = NULL;
    for(int i=0;i<arr.size();i++){
        head = insertAtHead(head,arr[i]);
    }
    if(isPresent(head,-7))
        cout<<"Element is Present"<<endl;
    return 0;
}

ce31_middleLLUsingFastSlowPtr.cpp

/*
    Middle Element  :   This is an easy problem! Apply runner technique to find mid-point of a given linked list in a single pass.
    Input           :   Head of the Linked List is given as input.  1->2->3->4->5->6->7->8
    Output          :   4
*/

#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

// Method to insert element at the head with the refernce method
void insertAtHead(Node* &headLL, int data){
    // if node is empty and we need to insert an element
    if(headLL == NULL){
        headLL = new Node(data);
        return;
    }   

    // if node is not empty and we need to insert an element at head  
    Node *temp = new Node(data);
    temp->next = headLL;
    headLL = temp;  
}

// Display the entire LL elements 
void displayLL(Node *headDisplayLL){
    while(headDisplayLL != NULL){
        cout<<headDisplayLL->data<<"-->";
        headDisplayLL = headDisplayLL->next;
    }
    cout<<endl;   
}

int getMid(Node *head){
    //Complete this function to return data middle node
    Node *fastPtr=head, *slowPtr=head;
    while(fastPtr != NULL and fastPtr->next != NULL and fastPtr->next->next != NULL){
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }
    return slowPtr->data;
}

int main(){
    Node *head = NULL;
    vector<int> arr{1,2,3,4};
    for(int i=0;i<arr.size();i++)
        insertAtHead(head,arr[i]);
    cout<<"Insert at Head is done for head"<<endl;

    int data = getMid(head);
    cout<<"Mid data: "<<data<<endl;
    return 0;
}

ce32_KthElementFromLastOfLL.cpp

/*
    Kth Element     :   Implement a function that returns the Kth last of element from the linked list, in a single pass. You can assume K will be less than / equal to length of linked list.
                        (Hint : Use two pointers similar to Runner Technique)
    Input           :   You will get head of the linked list.1 -> 2 -> 3 -> 4 -> 5 ->6 ->7
                        K = 3
    Output          :   5
*/

#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

// Method to insert element at the head with the refernce method
void insertAtHead(Node* &headLL, int data){
    // if node is empty and we need to insert an element
    if(headLL == NULL){
        headLL = new Node(data);
        return;
    }   

    // if node is not empty and we need to insert an element at head  
    Node *temp = new Node(data);
    temp->next = headLL;
    headLL = temp;  
}

// Display the entire LL elements 
void displayLL(Node *headDisplayLL){
    while(headDisplayLL != NULL){
        cout<<headDisplayLL->data<<"-->";
        headDisplayLL = headDisplayLL->next;
    }
    cout<<endl;   
}

int kthLastElement(Node *head, int k){
    //Complete this function to return kth last element
    Node *mainPtr = head, *refPtr = head;
    for(int i=1;i<k;i++)
        refPtr = refPtr->next;
        
    while(refPtr->next != NULL){
        refPtr = refPtr->next;
        mainPtr = mainPtr->next;
    }
    return mainPtr->data;
}
int main(){
    Node *head = NULL;
    vector<int> arr{45,56,-2,10};
    for(int i=0;i<arr.size();i++)
        insertAtHead(head,arr[i]);
    cout<<"Insert at Head is done for head"<<endl;

    int data = kthLastElement(head,2);
    cout<<"Kth from last of LL: "<<data<<endl;
    return 0;
}

slidingWindowSumOfSubArray.cpp

#include<iostream>
#include<vector>

int maxSumSubarray(std::vector<int> num, int elementLength){
    int len =num.size();
    int maxSum = 0, windowSum = 0;
    // baseCase
    if(len < elementLength){
        std::cout<<"Array length is too small"<<std::endl;
        return 0;
    }

    // calculating the sum of first 3 elements as per this example
    for(int i=0;i<elementLength;i++){
        windowSum += num[i];
    }
    maxSum = windowSum; //  Max sum holds the first window value, where window sum holds the same but keep on changed in the below loop
    // Starting the i from 3 as we already calculated the first 3s sum
    for(int i=elementLength;i<len;i++){
        // already maxSum is from num[0] to num[2], now are adding num[4] and removing num[0]
        // Thereby we can calculate the next element into sum and remove first element from sum
        windowSum += num[i] - num[i-elementLength]; 
        maxSum = std::max(maxSum,windowSum);    //checcking whether which is max
    }

    return maxSum;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 10, 7, 8, 9};
    int k = 3;
    std::cout << "Maximum sum of subarray of size " << k << " is: " << maxSumSubarray(nums, k) << std::endl;
    return 0;
}
