class Solution {
public:
    bool bfs(
        vector<vector<int>>& graph, int i, vector<bool> &vis,
        vector<bool> &a, vector<bool> &b
    ){
        queue<int> rem;
        rem.push(i);
        vis[i] = true;

        while(rem.size()){
            int u = rem.front();
            rem.pop();

            // 0 (a)    2(a)
            // 1 3 (b)

            // q => 2
            for(int v : graph[u]){
                if(a[u] && a[v]){
                    a[v] = false;
                    b[v] = true;
                } else if(b[u] && b[v]){
                    cout<<u<<" "<<v<<endl;
                    return false;
                }
                if(!vis[v]){
                    vis[v] = true;
                    rem.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> a(n, false);
        vector<bool> b(n, false);

        for(int i=0; i<n; i++)
            a[i] = true;

        vector<bool> vis(n, false);
        for(int i=0; i<n; i++){
            if(!vis[i])
                if(bfs(graph, i, vis, a, b) == false)
                    return false;
        }
        
        return true;
    }
};