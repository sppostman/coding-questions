class Node {
    public:
    int key;
    int value;
    Node *prev, *next;
    Node(int _key, int _value){
        this->key = _key;
        this->value = _value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};
class DoublyLinkedList {
    Node *head;
    Node *tail;

    public:
    DoublyLinkedList(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void insert(Node *newNode){
        newNode->prev = head;
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
    }

    int deleteLast(){
        Node *deleted = tail->prev;
        tail->prev = deleted->prev;
        deleted->prev->next = tail;

        int deletedKey = deleted->key;
        delete deleted;
        return deletedKey;
    }

    void placeAtHead(Node* node){
        if(node->prev != nullptr)
            node->prev->next = node->next;
        if(node->next != nullptr)
            node->next->prev = node->prev;
        
        node->prev = nullptr;
        node->next = nullptr;
        insert(node);
    }
};
class LRUCache {
public:
    int capacity;
    DoublyLinkedList dll;
    unordered_map<int, Node*> cache;

    public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        dll.placeAtHead(cache[key]);
        return cache[key]->value;
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end()){
            if(cache.size() == capacity){
                cache.erase(dll.deleteLast());
            }
            cache[key] = new Node(key, value);
        } else {
            cache[key]->value = value;
        }

        dll.placeAtHead(cache[key]);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */