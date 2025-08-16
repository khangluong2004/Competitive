#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
#include <set>
#include <map>

using namespace std;

struct cmpLess{
    bool operator() (int a, int b) const {
        return a < b;
    }
};

class customObj{
public:
    int x;
public:
    customObj(int x){
        cout << "Creating " << x << endl;
        this->x = x;
    }

    // Rule of three
    // Copy constructor
    customObj(const customObj& copyObj){
        cout << "Custom copy constructor" << copyObj.x << endl;
        this->x = copyObj.x;
    }

    // Copy assignment
    customObj& operator=(const customObj& copyObj){
        cout << "Custom copy assignment" << copyObj.x << endl;
        if (this == &copyObj){
            return *this;
        }

        this->x = copyObj.x;
        return *this;
    }

    // Destructor
    ~customObj(){
        cout << this->x << " " << "Destructor called" << endl;
    }

    int getX() const {
        return this->x;
    }

    // Override comparison
    bool operator<(const customObj& obj2) const {
        return this->x < obj2.getX();
    }
};

int main(int argc, char* argv[]){
    // Dynamic array
    vector<int> dynamicArr(100, 1);
    dynamicArr.push_back(101);
    cout << "Dynamic array: " << dynamicArr[dynamicArr.size() - 1] << endl;

    

    // Linked list
    list<int> linkedList;
    linkedList.push_front(1);
    linkedList.push_back(2);

    auto it = find(linkedList.begin(), linkedList.end(), 2);
    if (it != linkedList.end()){
        linkedList.insert(it, 3);
        linkedList.insert(it, 4);
    }

    cout << "Linked list: ";
    for (auto it = linkedList.begin(); it != linkedList.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    cout << "For each: ";
    for (auto num: linkedList){
        cout << num << " ";
    }
    cout << endl;

    // Hashtable
    unordered_map<int, int> hashTable;
    hashTable[1] = 10;
    hashTable[15] = 9;

    for (auto kv: hashTable){
        cout << "Key: " << kv.first << " ";
        cout << "Value: " << kv.second << endl;
    }

    // Binary min heap
    auto cmp = [](const int& a, const int& b){return a > b;};
    priority_queue<int, vector<int>, decltype(cmp)> minHeap(cmp);
    // priority_queue<int, vector<int>, cmpLess> maxHeap;
    priority_queue<int> maxHeap;

    vector<int> data = {1, 1, 1, 2, 10, 3, 5, 99, 19, 57, 57};

    for (auto num: data){
        minHeap.push(num);
        maxHeap.push(num);
    }

    cout << "Min Heap: " << minHeap.top() << endl;
    cout << "Max Heap: " << maxHeap.top() << endl;

    // Balanced binary search tree
    auto cmpMultiSet = [](int a, int b){return a > b;};

    multiset<int, decltype(cmpMultiSet)> decreasingTree(cmpMultiSet);

    for (auto num: data){
        decreasingTree.insert(num);
    } 

    cout << "Multiset (binary tree): ";
    for (auto num: decreasingTree){
        cout << num << " ";
    }
    cout << endl;
    cout << *decreasingTree.begin() << " " << *(--decreasingTree.end()) << endl; 

    multiset<int, cmpLess> increasingTree;

    for (auto num: data){
        increasingTree.insert(num);
    }

    // Erase all values of 57, not just one of them
    increasingTree.erase(57);
    increasingTree.insert(59);

    cout << "Multiset: ";
    for (auto num: increasingTree){
        cout << num << " ";
    }
    cout << endl;

    multiset<customObj> customTree;
    customTree.emplace(10);
    customTree.emplace(11);
    customTree.emplace(20);
    
    cout << "Multiset of custom object" << endl;
    for (auto& obj: customTree){
        cout << obj.getX() << " ";
    }
    cout << endl;

    cout << "Test erasing obj" << endl;
    customObj* check = new customObj(59);

    // Call copy constructor
    customObj check2 = *check;
    check2.x = 100;
    cout << "Test copy constructor" << endl;
    cout << check->x << " " << check2.x << endl;

    customTree.insert(*check);

    cout << "Multiset of custom object" << endl;
    for (auto& obj: customTree){
        cout << obj.getX() << " ";
    }
    cout << endl;

    customTree.erase(*check);

    cout << "Multiset of custom object" << endl;
    for (auto& obj: customTree){
        cout << obj.getX() << " ";
    }
    cout << endl;

    // Map
    map<int, int> treeMap;
    treeMap[10] = 11;
    treeMap[11] = 19;

    cout << "Test Tree Map" << endl;
    for (auto pair: treeMap){
        cout << pair.first << ": " << pair.second << endl;
    }


    return 0; 
}