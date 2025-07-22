#include<iostream>
#include<unordered_map>

using namespace std;

int main(){

// Declaration: C++ supports multiple implementations, but we will be using
// std::unordered_map. Specify the data type of the keys and values.
unordered_map<int, int> hashMap1;

// If you want to initialize it with some key value pairs, use the following syntax:
unordered_map<int, int> hashMap = {{1, 2}, {5, 3}, {7, 2}};

// Checking if a key exists: use the following syntax:
if(hashMap.find(1) != hashMap.end()){ // true (1)
    cout<<"True"<<endl;
}
else{
    cout<<"False"<<endl;
}
if(hashMap.find(9) != hashMap.end()){ // false (0)
    cout<<"True"<<endl;
}
else{
    cout<<"False"<<endl;
}
// Accessing a value given a key: use square brackets, similar to an array.
hashMap[5]; // 3

// Note: if you were to access a key that does not exist, it creates the key with a default value of 0.
hashMap[342]; // 0

// Adding or updating a key: use square brackets, similar to an array.
// If the key already exists, the value will be updated
hashMap[5] = 6;

// If the key doesn't exist yet, the key value pair will be inserted
hashMap[9] = 15;

// Deleting a key: use the .erase() method.
hashMap.erase(9);

// Get size
cout<<hashMap.size(); // 3

// Iterate over the key value pairs: use the following code.
// .first gets the key and .second gets the value.
for (auto const& pair: hashMap) {
    cout << pair.first << " " << pair.second << endl;
}

unordered_map<int, int> myHashMap;
// myHashMap has integers for both keys and values
    
myHashMap[4] = 83;
cout << myHashMap[4] << endl; // Prints 83
    
// These two lines check if a key is in the map
//cout << (myHashMap.contains(4)) << endl; // Prints true (1)   ---> this is not working so we have to use the find() != end() method here
//cout << (myHashMap.contains(854)) << endl; // Prints false (0)
if(myHashMap.find(4) != myHashMap.end()){ // true (1)
    cout<<"True"<<endl;
}
else{
    cout<<"False"<<endl;
}
if(myHashMap.find(854) != myHashMap.end()){ // false (0)
    cout<<"True"<<endl;
}
else{
    cout<<"False"<<endl;
}

    
myHashMap[8] = 327;
myHashMap[45] = 82523;

// We can use either this to find the key, value pair or the below one using first and second
for (auto [key, val]: myHashMap) {
    cout << key << ": " << val << endl;
}
for( auto pairs: myHashMap){
    cout<<pairs.first<<": "<<pairs.second<<endl;
}

return 0;
}
