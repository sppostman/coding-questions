class DLLNode {
public:
    int key;
    int value;
    DLLNode *left;
    DLLNode *right;
    
    DLLNode(int k, int v){
        this->key = k;
        this->value = v;
    }
};

class DLL {
private:
    DLLNode *head;
    DLLNode *tail;

public:
    DLL(){
        head = new DLLNode(-1, -1);
        tail = new DLLNode(-1, -1);
        head->right = tail;
        tail->left = head;
    }

    void append(DLLNode *node){
        node->left = tail->left;
        node->left->right = node;
        node->right = tail;
        tail->left = node;
    }

    void detach(DLLNode *node){
        node->left->right = node->right;
        node->right->left = node->left;
        node->left = nullptr;
        node->right = nullptr;
    }

    bool isEmpty(){
        return head->right == tail || tail->left == head;
    }

    DLLNode* popFirst(){
        if(isEmpty())
            return nullptr;
        DLLNode* removed = head->right;
        head->right = removed->right;
        removed->right->left = head;
        return removed;
    }
};

class LRUCache {
private:
    int size;
    int capacity;
    DLL itemList;
    map<int, DLLNode*> itemSet;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        auto it = itemSet.find(key);
        if(it == itemSet.end())
            return -1;
        itemList.detach(it->second);
        itemList.append(it->second);
        return it->second->value;
    }
    
    void put(int key, int value) {
        auto it = itemSet.find(key);
        DLLNode *target;
        if(it == itemSet.end()){
            target = new DLLNode(key, value);

            if(this->size == this->capacity){
                auto removed = itemList.popFirst();
                if(removed != nullptr)
                    itemSet.erase(removed->key);
            } 
            else this->size++;
        } else {
            target = it->second;
            target->value = value;
            itemList.detach(target);
        }
        itemSet[key] = target;
        itemList.append(target);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */