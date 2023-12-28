
class Node {
    private:
    Node *children[26];
    bool ends;

    public:
    Node(){
        for(int i=0; i<26; i++)
            this->children[i] = NULL;
        ends = false;
    }

    bool isEnd(){
        return ends;
    }
    void setEnd(){
        ends = true;
    }
    Node* getChild(char c){
        return children[c-'a'];
    }
    Node* addChildIfNotExists(char c){
        int targetIdx = c-'a';
        if(children[targetIdx] == NULL)
            children[targetIdx] = new Node();
        return children[targetIdx];
    }
};

class Trie {
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *curr = root;
        for(char c : word){
            curr = curr->addChildIfNotExists(c);
        }
        curr->setEnd();
    }
    
    bool search(string word) {
        Node *curr = root;
        for(char c : word){
            if(curr == NULL){
                return false;
            }
            curr = curr->getChild(c);
        }
        return curr != NULL && curr->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *curr = root;
        for(char c : prefix){
            if(curr == NULL){
                return false;
            }
            curr = curr->getChild(c);
        }
        return curr != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */