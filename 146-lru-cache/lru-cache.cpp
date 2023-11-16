typedef struct Node {
    Node *left;
    Node *right;
    int key;
    int value;

    Node(int key, int value){
        left=NULL;
        right=NULL;
        this->key = key;
        this->value = value;
    }

    void updateValue(int value){
        this->value = value;
    }
} Node;

class LRUCache {
private:
    unordered_map<int, Node*> cached;
    Node *mostRecent;
    Node *leastRecent;
    int capacity;

    void removeLeastRecent(){
        Node *target = leastRecent;
        if(target->left)
            target->left->right = NULL;
        leastRecent = target->left;
        cached.erase(target->key);
        printf("Cleanup %d (%d), size: %lu \n",target->key,target->value,cached.size());
        // free(target);
    }

    void use(int key){
        printf("Use %d \n", key);
        Node* targetNode = cached[key];

        if(mostRecent == targetNode){
            return;
        }

        if(targetNode->left){
            targetNode->left->right = targetNode->right;
        }
        if(targetNode->right){
            targetNode->right->left = targetNode->left;
        }
        if(targetNode == leastRecent){
            leastRecent = targetNode->left;
        }

        targetNode->left = NULL;
        targetNode->right = mostRecent;
        // mostRecent->left = targetNode;

        if(mostRecent)
            mostRecent->left = targetNode;
        if(!leastRecent)
            leastRecent = targetNode;
        mostRecent = targetNode;
    }

public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        mostRecent = NULL;
        leastRecent = NULL;
    }
    
    int get(int key) {
        if(cached.find(key) != cached.end()){
            use(key);
            return cached[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node* targetNode;

        if(cached.find(key) == cached.end()){
            printf("Put %d (Size: %lu)\n", key, cached.size()+1);
            targetNode = new Node(key, value);
            cached[key] = targetNode;
            if(!leastRecent)
                leastRecent = targetNode;
        } else {
            targetNode = cached[key];
            targetNode->updateValue(value);
        }

        use(key);

        if(cached.size() > capacity)
            removeLeastRecent();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */