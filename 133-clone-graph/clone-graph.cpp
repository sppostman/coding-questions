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
    Node* cloneit(Node* node, Node* parent, vector<bool> &vis, map<int, Node*> &newgraph){
        if(node == nullptr)
            return nullptr;
        vis[node->val] = true;
        if(newgraph.count(node->val)==0){
            newgraph[node->val] = new Node(node->val);
        }
        Node* newNode = newgraph[node->val];
        for(auto v : node->neighbors){
            if(!vis[v->val])
                cloneit(v, node, vis, newgraph);
        }
        for(auto v : node->neighbors)
            newNode->neighbors.push_back(newgraph[v->val]);
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        map<int, Node*> newgraph;
        vector<bool> vis(105);
        return cloneit(node, nullptr, vis, newgraph);
    }
};