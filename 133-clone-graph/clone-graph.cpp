/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfsClone(Node *node, vector<bool> &vis, vector<Node*> &nodes){
        if(node == NULL)
            return NULL;
        // printf("At %d \n", node->val);

        Node *curr = nodes[node->val];
        if(curr == NULL){
            curr = new Node(node->val);
            nodes[node->val] = curr;
        }
        vis[node->val]=true;

        for(Node* neighbor : node->neighbors){
            if(!vis[neighbor->val]){
                // printf("(from %d) go to %d\n",node->val,neighbor->val);
                curr->neighbors.push_back(
                    dfsClone(neighbor,vis,nodes)
                );
            }else{
                curr->neighbors.push_back(nodes[neighbor->val]);
                // printf("(from %d), already done %d\n",
                // node->val,neighbor->val);
            }
        }


        return curr;
    }

    Node* cloneGraph(Node* node) {
        // map<int, Node*> nodes;
        vector<Node*> nodes(105, NULL);
        vector<bool> vis(105);
        return dfsClone(node, vis, nodes);
    }
};