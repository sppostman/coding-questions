class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjMat, vector<bool> &visited){
        visited[node] = true;
        for(int i=0;i<adjMat.size();i++){
            if(adjMat[node][i] && !visited[i]){
                dfs(i, adjMat,visited);
            }
        }
    }
    void bfs(int node, vector<vector<int>>& adjMat, vector<bool> &visited){
        queue<int> rem;
        rem.push(node);
        visited[node] = true;

        while(!rem.empty()){
            int curr = rem.front();
            rem.pop();
            for(int i=0;i<adjMat.size();i++){
                if(adjMat[curr][i] && !visited[i]){
                    visited[i] = true;
                    rem.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adjMat) {
        int v = adjMat.size();
        vector<bool> visited(v);
        int prov=0;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                prov++;
                // dfs(i,adjMat,visited);
                bfs(i,adjMat,visited);
            }
        }
        return prov;
    }
};