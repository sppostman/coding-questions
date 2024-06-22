vector<int> path;
class Solution {
public:
    bool dfs(int u, vector<vector<int>>& graph, vector<int> &vis, vector<int> &res){
        vis[u] = 1;
        bool allGood = true;

        cout<<u<<endl;

        for(int v : graph[u]){
            if(vis[v] == 0){
                if(!dfs(v, graph, vis, res))
                    allGood = false;
            } else if(vis[v] == 1)
                allGood = false;
        }
        if(allGood)
            res.push_back(u);
        vis[u] = allGood ? 2 : 1;
        return allGood;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> res;
        for(int i=0; i<n; i++)
            if(vis[i] == 0)
                dfs(i, graph, vis, res);
        sort(res.begin(), res.end());
        return res;
    }
};