#include <iostream>
#include <map>

class Node {
public:
    int key, value;
    Node* next;
    Node* prev;

    Node() {
        key = value = -1;
        next = prev = NULL;
    }
    Node(int k, int v) {
        key = k;
        value = v;
        next = prev = NULL;
    }
};

class LRUCache {
private:
    std::map<int, Node*> mpp;
    int cap;
    Node* head;
    Node* tail;

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAtHead(Node* node) {
      Node* nextNode = head->next;

      head->next = node;
      node->prev = head;
      node->next = nextNode;
      nextNode->prev = node;
    }

public:
    LRUCache(int capacity) {
        mpp.clear();
        cap = capacity;
        head = new Node();
        tail = new Node();
        tail->prev = head;
        head->next = tail;
    }

    int get(int key_) {
        if(mpp.find(key_) == mpp.end()) {
            return -1;
        }
        Node* node = mpp[key_];
        int val = node->value;
        deleteNode(node);
        insertAtHead(node);
        return val;
    }

    void put(int key_, int val) {
        if(mpp.find(key_) != mpp.end()) {
            Node* node = mpp[key_];
            node->value = val;
            deleteNode(node);
            insertAtHead(node);
            return;
        }
        if(mpp.size() == cap) {
            Node* node = tail->prev;
            mpp.erase(node->key);
            deleteNode(node);
        }
        Node* tempNode = new Node(key_,val);
        mpp[key_] = tempNode;
        insertAtHead(tempNode);
    }
};

int main(int argc, char*argv[]) {
    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    std::cout<<cache.get(1)<< " ";
    cache.put(3,3);
    std::cout<<cache.get(2)<<" ";
    cache.put(4,4);
    std::cout<<cache.get(1)<< " ";
    std::cout<<cache.get(3)<< " ";
    std::cout<<cache.get(4)<< " "<<std::endl;
    return 0;
}