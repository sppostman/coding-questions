class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<bool> vis(n, false);

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(auto pr : prerequisites){
            adj[pr[1]].push_back(pr[0]);
            indegree[pr[0]]++;
        }

        vector<int> path;
        queue<int> rem;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                rem.push(i);
                path.push_back(i);
            }
        }
        while(rem.size() && path.size()<n){
            int curr = rem.front();
            rem.pop();
            
            for(int nxt : adj[curr]){
                indegree[nxt]--;
                if(indegree[nxt] == 0){
                    rem.push(nxt);
                    path.push_back(nxt);
                }
            }
        }
        if(path.size() != n)
            path.clear();
        return path;
    }
};