typedef struct Node {
    Node* children[26];
    bool ends;

    Node(){
        for(int i=0; i<26; i++)
            this->children[i] = NULL;
        this->ends = false;
    }

    bool hasChar(char ch){
        int idx = ch - 'a';
        return children[idx] != NULL;
    }

    Node* getChar(char ch){
        int idx = ch - 'a';
        return children[idx];
    }

    Node* addChildIfNotExists(char ch){
        int idx = ch - 'a';
        if(!children[idx])
            children[idx] = new Node();
        return children[idx];
    }

    void setEnd(){
        ends = true;
    }
} Node;

class Trie {
private:
    Node* root;

public:

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;

        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            node = node->addChildIfNotExists(ch);
        }

        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(! node->hasChar(ch) )
                return false;
            node = node->getChar(ch);
        }

        return node->ends;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        
        for(int i=0; i<prefix.size(); i++){
            char ch = prefix[i];
            if(! node->hasChar(ch) )
                return false;
            node = node->getChar(ch);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */