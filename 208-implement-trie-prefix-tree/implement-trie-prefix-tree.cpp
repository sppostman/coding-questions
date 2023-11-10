typedef struct Node {
    Node* children[26];
    bool ends;
} Node;

class Trie {
private:
    Node* newNode(){
        Node* newer = new Node();
        for(int i=0; i<26; i++)
            newer->children[i] = NULL;
        newer -> ends = false;
        return newer;
    }

public:
    Node* root;

    Trie() {
        root = newNode();
    }
    
    void insert(string word) {
        Node *node = root;

        for(int i=0; i<word.size(); i++){
            char ch = word[i] - 'a';
            if(! node->children[ch] )
                node->children[ch] = newNode();
            node = node->children[ch];
        }

        node->ends = true;
    }
    
    bool search(string word) {
        Node *node = root;
        
        for(int i=0; i<word.size(); i++){
            char ch = word[i] - 'a';
            if(! node->children[ch] )
                return false;
            node = node->children[ch];
        }

        return node != NULL && node->ends;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        
        for(int i=0; i<prefix.size(); i++){
            char ch = prefix[i] - 'a';
            if(! node->children[ch] )
                return false;
            node = node->children[ch];
        }

        return node != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */