typedef struct Node {
    private:
    int key;
    int value;
    
    public:
    Node *left;
    Node *right;

    Node(int key, int value){
        left=NULL;
        right=NULL;
        this->key = key;
        this->value = value;
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
} Node;

class DLL {
    Node *head;
    Node *tail;

    public:
    DLL(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->right = tail;
        tail->left = head;
    }

    Node* getFirstNode(){
        return head->right != tail ? head->right : NULL;
    }

    Node* getLastNode(){
        return tail->left != head ? tail->left : NULL;
    }

    Node* detachNode(Node *node){
        node->left->right = node->right;
        node->right->left = node->left;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    void removeNode(Node *node){
        detachNode(node);
        delete node;
    }

    int removeLastNode(){
        int removedKey = -1;
        Node *lastNode = getLastNode();
        if(lastNode){
            removedKey = lastNode->getKey();
            removeNode(lastNode);
        }
        return removedKey;
    }

    void addNodeToBeginning(Node *node){
        node->right = head->right;
        node->left = head;
        head->right->left = node;
        head->right = node;
    }
};


class LRUCache {
private:
    unordered_map<int, Node*> cached;
    DLL ordered;
    int capacity;

    void removeLeastRecent(){
        int removedKey = ordered.removeLastNode();
        if(removedKey != -1){
            // printf("Remove %d \n", removedKey);
            cached.erase(removedKey);
        }
    }

    Node* use(int key){
        if(cached.find(key) == cached.end())
            return NULL;

        // printf("Use %d \n", key);
        Node* targetNode = cached[key];
        ordered.detachNode(targetNode);
        ordered.addNodeToBeginning(targetNode);
        return targetNode;
    }

public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(cached.find(key) != cached.end()){
            Node *existingNode = use(key);
            return existingNode->getValue();
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cached.find(key) == cached.end()){
            // Whole point of capacity is to have max limit on nodes we can store
            if(cached.size() == capacity)
                removeLeastRecent();
            Node *newNode = new Node(key, value);
            ordered.addNodeToBeginning(newNode);
            cached[key] = newNode;
        } else {
            Node *existingNode = use(key);
            existingNode->updateValue(value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */