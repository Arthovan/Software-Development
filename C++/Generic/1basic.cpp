#include<iostream>
int main(){
    /*  std     =   Standard
        cout    =   Character output
        <<      =   Insertion operator
        ::      =   Scope resolution operator
        >>      =   Extraction operator */

    std::cout << "Hai" << '\n';         // "\n" will create a new line after the output, this is better in performance compared to endl
    std::cout << "Arun" << std::endl;   // Benefit of using std::endl is that endl will flush the output buffer

    std::string name;
    std::string fullname;
    std::cin >> name;                   //  this will not read spaces, once we type "Arun Parkugan". Only Arun will be taken as input
    std::cout << "Hello " << name << '\n';
    //  To avoid the space conflict we need to use "getline" function
    std::getline(std::cin,fullname);    //  As we use '\n' at the end of the cin previously and that is affecting here in getline, to avoid this we need to use std::ws (whitespace)
    std::cout << "Hello " << fullname << '\n';
    std::getline(std::cin >> std::ws,fullname);
    std::cout << "Hello " << fullname << '\n';
	return 0;

}
/////////////////typeid
#include<iostream>
#include<typeinfo>


using namespace std;

int main(int argc, char* argv[]) {
    int val = 10;
    float tem = 8.96;
    char ch = 'a';
    bool flag = true;
    string s {"This is a string"};
    auto x = s;     //  auto should be initialised to know its type 
    //auto b; // this will throw an error as compiler doesnt know what its data type during compilation
    cout<<"X is a "<<s<<endl;
    cout<<"Type of val is "<<typeid(val).name()<<endl;
    cout<<"Type of tem is "<<typeid(tem).name()<<endl;
    cout<<"Type of ch is "<<typeid(ch).name()<<endl;
    cout<<"Type of flag is "<<typeid(flag).name()<<endl;
    cout<<"Type of s is "<<typeid(s).name()<<endl;
    cout<<"Type of x is "<<typeid(x).name()<<endl;
    return 0;
}

//////////////////compound interest calculator
#include<iostream>
#include<iomanip>   // contain setprecision
#include<cmath> // contains power

using namespace std;

int main(int argc, char* argv[]) {
    double compoundValue = 0;
    double interestRate = 0;
    double initialValue = 0;
    int years = 0;
    bool flag = true;
    while(flag) {
        cout<<"Enter the tenure in years from 1 - 50 : ";
        cin>>years;
        if(years >= 1 and years < 51)
            flag = false;            
    }

    flag = true;

    while(flag) {
        cout<<"Enter the initial investment : ";
        cin>>initialValue;
        if(initialValue >= 1 and initialValue < 1000000000)
            flag = false;       
    }

    flag = true;

    while(flag) {
        cout<<"Enter the interest rate : ";
        cin>>interestRate;
        if(interestRate >= 1 and interestRate < 100)
            flag = false;       
    }

    // Compound interest calculation
    // Formula : A = P(1+r)^t
    //compoundValue = initialValue * pow(1 + (interestRate/100), years);

    // Alternative iterative approach:
    compoundValue = initialValue;
    for(int i = 0; i < years; i++) {
        compoundValue = compoundValue * (1 + interestRate/100);
    }

    cout<<fixed<<setprecision(2);   // to set a decimal precision in our code
    cout<<"The value of initial investement "<<initialValue<<" for "<<years<<" years with interest rate of "<<interestRate<<"% is : "<<compoundValue<<endl;
    cout<<"Total interest earned: "<<(compoundValue - initialValue)<<endl;
    return 0;
}

///////////////////////////////////qualifiers
/*  Qualifiers are used to adjust a quality of an object or variable
    CV Qualifiers       Storage Qualifiers
    -------------       ------------------
        const               static
        mutable             register
        volatile            extern
    */

    #include<iostream>

    using namespace std;

    int func() {
        static int x{7};
        return ++x;
    }

    int main(int argc, char* argv[]) {
        int i{42};
        cout<<"The integer is "<<i<<endl;
        i = 56;
        cout<<"The integer is "<<i<<endl;
        const int y = 67;
        cout<<"The integer is "<<y<<endl;
        //y = 90; // we cant do this as compiler throws an error
        cout<<"The integer value is  : "<<func()<<endl;
        cout<<"The integer value is  : "<<func()<<endl;
        cout<<"The integer value is  : "<<func()<<endl;
        return 0;
    }

/////////////////////////////////sorting Algorithms
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool compare(int a, int b) {
    return a > b;
}
void inbuiltSort(vector<int> ibs){
    //  Time Complexity :   O(nlogn)
    int n = ibs.size();
    // we can make use of inbuilt function sort(), with our own compartor to make it as reverse 

    sort(ibs.begin(), ibs.end(),greater<int>());  //  general sorting method with inbuilt reverse
    cout<<"Inbuilt Revesere output is       : ";
    for(auto out : ibs) {
        cout<<out<<" ";
    }
    cout<<endl;

    sort(ibs.begin(), ibs.end());  //  general sorting method
    cout<<"Inbuilt Sorted output is         : ";
    for(auto out : ibs) {
        cout<<out<<" ";
    }
    cout<<endl;

    sort(ibs.begin(), ibs.end(),compare);  //  general sorting method with our own comparator
    cout<<"Inbuilt Sort + own reverse is    : ";
    for(auto out : ibs) {
        cout<<out<<" ";
    }
    cout<<endl; 


}

void selectionSort(vector<int> &ss) {
    //  Time Complexity :   O(n^2)
    int size = ss.size();

    for(int i = 0; i < size - 1; i++) { // swap will be done in the inner loop where last element also included so only we are doing "size - 1" iterations here
        int min = i;
        for(int j = i + 1; j < size; j++) { // as we are including "i" already in "min" so we dont have to compare it again with "i" in "j" so only "i + 1"
            if(ss[min] > ss[j]) {
                min = j;
            }
        }
        if(min != i) // this check is not mandatoty, even without this also code works 
            swap(ss[min], ss[i]);
    }
    cout<<"Selection Sorted output is       : ";
    for(auto out : ss) {
        cout<<out<<" ";
    }
    cout<<endl;
}

void bubbleSort(vector<int> bs) {
     //  Time Complexity :   O(n^2)
    int size = bs.size();

    for(int i = 0; i < size; i++) {
        bool didSwap = false;
        for(int j = 0; j < size-i-1; j++) {
            if(bs[j] > bs[j + 1]) {
                swap(bs[j], bs[j+1]);
                didSwap = true;
            }
        }
        if(!didSwap) break;
    }
    cout<<"Bubble Sorted output is          : ";
    for(auto out : bs) {
        cout<<out<<" ";
    }
    cout<<endl;
}

void insertionSort(vector<int> is) {
     //  Time Complexity :   O(n^2)
    int size = is.size();

    for(int i = 1; i < size; i++) {
        int current = is[i];    // Current element as "current"
        int j = i - 1;   
         // Shift elements that are greater than key by one position
        while(j >= 0 && is[j] > current) {
            is[j + 1] = is[j];
            j--;
        }
        is[j + 1] = current;    // Insert current at correct position
    }
    cout<<"Insertion Sorted output is       : ";
    for(auto out : is) {
        cout<<out<<" ";
    }
    cout<<endl;
}
void merge(vector<int> &mer, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high) {
        if(mer[left] <= mer[right]) {
            temp.push_back(mer[left]);
            left++;
        } else {
            temp.push_back(mer[right]);
            right++;
        }
    }
    while(left <= mid) {
        temp.push_back(mer[left]);
        left++;
    }
    while(right <= high) {
        temp.push_back(mer[right]);
        right++;
    }

    for(int i = low; i <= high; i++) {
        mer[i] = temp[i - low];
    }
}

void mergeSortHelper(vector<int> &msh, int low, int high) {
    if(low >= high) return; // low never goes greater than high, only chance is equal to high, but just for safety we are writing ">=" here

    int mid = (low + high) / 2;
    mergeSortHelper(msh,low, mid);
    mergeSortHelper(msh,mid + 1,high);
    merge(msh, low, mid, high);
}

void mergeSort(vector<int> ms) {
     //  Time Complexity :   O(nlogn)
    int size = ms.size();
    mergeSortHelper(ms,0,size-1);

    cout<<"Merge Sorted output is           : ";
    for(auto out : ms) {
        cout<<out<<" ";
    }
    cout<<endl;
}

int main(int argc, char* argv[]) {
    vector<int> arr = {7,1,4,6,9,2,8};
    selectionSort(arr);
    bubbleSort(arr);
    insertionSort(arr);
    mergeSort(arr);
    inbuiltSort(arr);

    return 0;
}

