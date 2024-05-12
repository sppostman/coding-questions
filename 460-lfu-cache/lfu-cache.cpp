class Node {
    public:
    int val;
    Node *prev, *next;
    Node(int _val){
        val = _val;
        prev = nullptr;
        next = nullptr;
    }
};
class LinkedHashSet {
    unordered_map<int, Node*> elements;
    Node *head, *tail;

    public:
    LinkedHashSet(){
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }
    void insert(int x){
        Node *newNode = new Node(x);
        elements[x] = newNode;
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev->next = newNode;
        tail->prev = newNode;
    }
    void erase(int x){
        if(elements.find(x) == elements.end())
            return;

        Node* removed = elements[x];
        removed->next->prev = removed->prev;
        removed->prev->next = removed->next;
        elements.erase(x);
        delete removed;
    }
    int pop_front(){
        if(head->next == tail)
            return -1;
        int popped = head->next->val;
        erase(popped);
        return popped;
    }
    int size(){
        return elements.size();
    }
};

class LFUCache {
public:
    unordered_map<int, int> keyVal;
    unordered_map<int, int> keyCount;
    unordered_map<int, LinkedHashSet> freqKeys;
    int capacity;
    int min;

    LFUCache(int _capacity) {
        capacity = _capacity;
        min = -1;
    }

    void useKey(int key){
        freqKeys[keyCount[key]].erase(key);
        if(min == keyCount[key] && freqKeys[keyCount[key]].size() == 0)
            min++;
        keyCount[key]++;
        freqKeys[keyCount[key]].insert(key);
    }
    
    int get(int key) {
        if(keyVal.find(key) == keyVal.end())
            return -1;
        useKey(key);
        return keyVal[key];
    }
    
    void put(int key, int value) {
        if(capacity == 0)
            return;

        if(keyVal.find(key) != keyVal.end()){
            keyVal[key] = value;
            useKey(key);
            return;
        }

        if(keyVal.size() == capacity){
            // Remove least freq
            int removedKey = freqKeys[min].pop_front();
            
            // Don't touch min, as its going to be set 1 anyways
            keyCount.erase(removedKey);
            keyVal.erase(removedKey);
        }

        min = 1;
        keyVal[key] = value;
        useKey(key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */