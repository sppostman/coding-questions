typedef struct Node {
    Node* children[2];
    Node(){
        children[0] = NULL;
        children[1] = NULL;
    }
    Node* addIfNotExists(int bit){
        if(!children[bit])
            children[bit] = new Node();
        return children[bit];
    }
    bool hasBit(int bit){
        return children[bit] != NULL;   
    }
    Node* getBit(int bit){
        return children[bit];
    }
}Node;

class Trie {
    private:
        Node *root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(int num){
            Node *node = root;

            for(int i=31; i>=0; i--){
                node = node->addIfNotExists((num >> i) & 1);
            }
        }
        int getXorCandidate(int x){
            Node *node = root;
            int best = 0;
            for(int i=31; i>=0; i--){
                int desired = 1-((x >> i) & 1);
                if(node->hasBit(desired)){
                    node = node->getBit(desired);
                    best |= desired << i;
                } else {
                    node = node->getBit(1-desired);
                    best |= 1-desired << i;
                }
            }
            return best;
        }
};

// 0 1 1
// 1 0 0

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int n : nums){
            trie.insert(n);
        }

        int mx = 0;
        for(int n : nums){
            // printf("%d ^ %d\n", n, n^trie.getXorCandidate(n));
            mx = max(mx, n^trie.getXorCandidate(n));
        }
        return mx;

        // int mx = 0;
        // int n= nums.size();
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         mx = max(mx, nums[i]^nums[j]);
        //     }
        // }
        // return mx;
    }
};