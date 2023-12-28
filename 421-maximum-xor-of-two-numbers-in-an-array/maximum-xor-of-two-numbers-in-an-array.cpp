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
            Node *curr = root;
            for(int i=31; i>=0; i--){
                curr = curr->addIfNotExists((num >> i) & 1);
            }
        }
        int getXor(int x){
            int xorResult = 0;
            Node *curr = root;
            for(int i=31; i>=0; i--){
                int bit = (x>>i) & 1;
                int desired = bit ^ 1; // opposite bit
                int best = curr->hasBit(desired) ? desired : bit;
                curr = curr->getBit(best);
                xorResult |= (bit ^ best) << i;
            }
            return xorResult;
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
            mx = max(mx, trie.getXor(n));
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