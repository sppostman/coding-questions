class Node {
    int key;
    int value;
    
    public:
    Node *left;
    Node *right;

    Node(int key, int value){
        this->key = key;
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
    int getKey(){
        return this->key;
    }
    int getValue(){
        return this->value;
    }
    void updateValue(int value){
        this->value = value;
    }
};
class DoublylinkedList {
    Node *head;
    Node *tail;
    public:
    DoublylinkedList(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->right = tail;
        tail->left = head;
    }
    Node* addNode(int key, int value){
        Node *newNode = new Node(key, value);
        tail->left->right = newNode;
        newNode->left = tail->left;
        tail->left = newNode;
        newNode->right = tail;
        return newNode;
    }
    int removeFirstNode(){
        if(isEmpty())
            return -1;
        Node *removed = head->right;
        int removedKey = removed->getKey();
        removed->right->left = head;
        head->right = removed->right;
        delete removed;
        return removedKey;
    }
    void removeNode(Node *node){
        node->left->right = node->right;
        node->right->left = node->left;
        delete node;
    }
    bool isEmpty(){
        return head->right == tail;
    }
};

class LFUCache {
public:
    unordered_map<int,pair<Node*,int>> keyNodeCounter;
    unordered_map<int, DoublylinkedList> countedKeys;
    int capacity = 0;
    int takenKeys = 0;
    int minCount = 0;

    LFUCache(int capacity) {
        this->capacity = capacity;    
    }
    
    int get(int key) {
        if(keyNodeCounter.find(key) == keyNodeCounter.end())
            return -1;
        Node *currNode = keyNodeCounter[key].first;
        int value = currNode->getValue();
        int count = keyNodeCounter[key].second;
        countedKeys[count].removeNode(currNode);

        if(minCount == count && countedKeys[count].isEmpty()){
            minCount++;
        }
        count++;
        keyNodeCounter[key] = { countedKeys[count].addNode(key, value), count };
        return value;
    }
    
    void put(int key, int value) {
        if(keyNodeCounter.find(key) != keyNodeCounter.end()){
            keyNodeCounter[key].first->updateValue(value);
            get(key);
            return;
        }

        if(takenKeys == capacity){
            int removedKey = countedKeys[minCount].removeFirstNode();
            keyNodeCounter.erase(removedKey);
            takenKeys--;
            // minCount need not be worried, as its going to be 1 after insertion of new key
        }

        keyNodeCounter[key] = {countedKeys[1].addNode(key, value), 1};
        minCount = 1;
        takenKeys++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */