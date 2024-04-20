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

        // for(int i=0;i<v;i++){
        //     if(!visited[i]){
        //         prov++;
        //         // dfs(i,adjMat,visited);
        //         bfs(i,adjMat,visited);
        //     }
        // }
        // return prov;

        vector<int> parents(v);
        for(int i=0; i<v; i++) parents[i] = i;
        for(int i=0; i<v; i++){
            for(int j=0; j<i; j++){
                if(adjMat[i][j]==1)
                    merge(i, j, parents);
            }
        }
        
        for(int i=0; i<v; i++){
            prov += findP(i, parents) == i;
        }
        return prov;
    }
    void merge(int u, int v, vector<int> &parents){
        parents[findP(v, parents)] = findP(u, parents);
    }
    int findP(int node, vector<int> &parents){
        if(parents[node] == node)
            return node;
        return parents[node] = findP(parents[node], parents);
    }
};