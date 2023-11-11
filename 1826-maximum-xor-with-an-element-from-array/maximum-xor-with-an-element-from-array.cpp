typedef struct Node {
    Node* children[2];
    int mn;
    Node(){
        mn = 1e9+5;
        children[0] = NULL;
        children[1] = NULL;
    }
    bool hasChild(int bit){
        return children[bit] != NULL;
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
        int getMaxXorWithoutMax(int num){
            Node *node = root;
            int maxXor = 0;
            for(int i=31; i>=0; i--){
                int currXorBit = num>>i & 1;
                if(node->hasChild(1-currXorBit)){
                    node = node->getChild(1-currXorBit);
                    maxXor |= 1<<i;
                }
                else
                    node = node->getChild(currXorBit);
            }
            return maxXor;
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

        // for(int n : nums)
        //     trie.insert(n);
        // vector<int> result;
        // for(auto &query : queries){
        //     result.push_back(trie.getMaxXor(query[0], query[1]));
        // }
        // return result;

        vector<int> result(queries.size());
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());

        vector<pair<int, pair<int,int>>> ques;
        for(int q=0; q<queries.size(); q++){
            auto &query = queries[q];
            ques.push_back({queries[q][1], {queries[q][0], q}});
        }
        sort(ques.begin(), ques.end());
        
        int i = 0;
        for(auto &query : ques){
            while(i<arr.size() && arr[i] <= query.first)
                trie.insert(arr[i++]);

            // No elmeent in trie
            if(i==0)
                result[query.second.second] = -1;
            else
                result[query.second.second] = trie.getMaxXorWithoutMax(query.second.first);
            // printf("Process query-%d, mx(%d) => %d\n", query.second.second, query.first, result[query.second.second]);
        }

        return result;
    }
};