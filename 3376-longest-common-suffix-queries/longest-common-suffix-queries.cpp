class TrieNode {
    public:
    TrieNode* children[26];
    int pfCount = 0;
    int minStrHere = INT_MAX;
    int minStrIdx = -1;
    bool ends = false;

    TrieNode(){
        for(int i=0; i<26; i++)
            children[i] = nullptr;
    }

    int getChildIdx(char c){
        return c-'a';
    }

    bool hasChild(char c){
        int idx = getChildIdx(c);
        return children[idx] != nullptr;
    }

    int pfs(){
        return pfCount;
    }
    void markEnd(){
        ends = true;
    }
    TrieNode* getChild(char c){
        int idx = getChildIdx(c);
        return children[idx];
    }

    TrieNode* addOrMakeChild(char c, int strLength, int strIdx){
        int idx = getChildIdx(c);
        if(children[idx] == nullptr){
            children[idx] = new TrieNode();
        }
        children[idx]->pfCount++;
        if(strLength < children[idx]->minStrHere){
            children[idx]->minStrIdx = strIdx;
            children[idx]->minStrHere = strLength;
        }
        
        return children[idx];
    }
};

class Trie {
    TrieNode* root;

    public:
    Trie(){
        root = new TrieNode();
    }
    void addWord(string word, int strIdx){
        TrieNode* curr = root;    
        if(word.size() < root->minStrHere){
            root->minStrIdx = strIdx;
            root->minStrHere = word.size();
        }    
        for(char c : word){
            curr = curr->addOrMakeChild(c, word.size(), strIdx);
        }
        curr->markEnd();
    }
    int getWordIdx(string word){
        TrieNode* curr = root;        
        for(char c : word){
            if(!(curr->hasChild(c)))
                return curr->minStrIdx;
            curr = curr->getChild(c);
        }
        return curr->minStrIdx;
    }
};


class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie taken;
        for(int i=0; i<wordsContainer.size(); i++){
            string s = wordsContainer[i];
            reverse(s.begin(), s.end());
            taken.addWord(s, i);
        }

        vector<int> res;
        for(string s : wordsQuery){
            reverse(s.begin(), s.end());
            res.push_back(taken.getWordIdx(s));
        }
        return res;
    }
};