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
        int getMaxXor(int num){
            Node *node = root;
            int maxXor = 0;
            for(int i=31; i>=0; i--){
                int currXorBit = (num>>i) & 1;
                int desired = 1-currXorBit;
                int available = node->hasChild(desired) ? desired : currXorBit;

                node = node->getChild(available);
                maxXor |= (currXorBit ^ available)<<i;
                if(node == NULL)
                    return -1;
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

        // Offline queries
        vector<int> result(queries.size());
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int n=arr.size();

        typedef struct Query {
            int id;
            int num;
            int mx;
        } Query;

        vector<Query> ques(queries.size());
        for(int id=0; id<queries.size(); id++){
            ques[id].id = id;
            ques[id].num = queries[id][0];
            ques[id].mx = queries[id][1];
        }
        sort(ques.begin(), ques.end(), [](Query q1, Query q2){
            return q1.mx < q2.mx;
        });

        int insertedTill = 0;
        for(Query q : ques){
            while(insertedTill < n && arr[insertedTill] <= q.mx)
                trie.insert(arr[insertedTill++]);
            result[q.id] = trie.getMaxXor(q.num);
        }

        return result;
    }
};