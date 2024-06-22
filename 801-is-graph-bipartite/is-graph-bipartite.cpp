class Solution {
public:
    // bool bfs(
    //     vector<vector<int>>& graph, int i, vector<bool> &vis,
    //     vector<bool> &a, vector<bool> &b
    // ){
    //     queue<int> rem;
    //     rem.push(i);
    //     vis[i] = true;

    //     while(rem.size()){
    //         int u = rem.front();
    //         rem.pop();

    //         for(int v : graph[u]){
    //             if(a[u] && a[v]){
    //                 a[v] = false;
    //                 b[v] = true;
    //             } else if(b[u] && b[v]){
    //                 return false;
    //             }
    //             if(!vis[v]){
    //                 vis[v] = true;
    //                 rem.push(v);
    //             }
    //         }
    //     }
    //     return true;
    // }

    bool dfs(int i, int currColor, vector<vector<int>>& graph, vector<int> &color){
        color[i] = currColor;

        for(int v : graph[i]){
            if(color[v] == -1){
                if(!dfs(v, 1-currColor, graph, color))
                    return false;
            } else if(color[i] == color[v])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);
        for(int i=0; i<n; i++)
            if(color[i] == -1)
                if(!dfs(i, 0, graph, color))
                    return false;
        return true;

        // vector<bool> a(n, false);
        // vector<bool> b(n, false);

        // for(int i=0; i<n; i++)
        //     a[i] = true;

        // vector<bool> vis(n, false);
        // for(int i=0; i<n; i++){
        //     if(!vis[i])
        //         if(bfs(graph, i, vis, a, b) == false)
        //             return false;
        // }
        // return true;
    }
};