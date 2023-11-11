typedef struct Node {
    Node* children[2];
    int mn;
    Node(){
        mn = 1e9+5;
        children[0] = NULL;
        children[1] = NULL;
    }
    Node* getChild(int bit){
        return children[bit];
    }
    Node* addIfNotExists(int bit, int num){
        if(!children[bit])
            children[bit] = new Node();
        children[bit]->mn = min(num, children[bit]->mn);
        return children[bit];
    }
} Node;

class Trie {
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(int num){
            Node *node = root;
            for(int i=31; i>=0; i--){
                node = node->addIfNotExists(num>>i & 1, num);
            }
        }
        int getMaxXor(int num, int mx){
            Node *node = root;
            int maxXor = 0;
            for(int i=31; i>=0; i--){
                int currXorBit = num>>i & 1;
                Node *desired = node->getChild(1-currXorBit);
                Node *undesired = node->getChild(currXorBit);

                if(desired && desired->mn <= mx){
                    node = desired;
                    maxXor |= 1<<i;
                } else if(undesired->mn <= mx) {
                    node = undesired;
                } else {
                    return -1;
                }
            }
            return maxXor;
        }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        for(int n : nums)
            trie.insert(n);
        vector<int> result;
        for(auto &query : queries){
            result.push_back(trie.getMaxXor(query[0], query[1]));
        }
        return result;
    }
};