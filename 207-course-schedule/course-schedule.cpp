class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        for(auto pr : prerequisites){
            adj[pr[1]].push_back(pr[0]);
            indegree[pr[0]]++;
        }

        queue<int> rem;
        for(int i=0; i<n; i++)
            if(indegree[i] == 0)
                rem.push(i);

        int taken = rem.size();
        while(rem.size() && taken<n){
            int u = rem.front();
            rem.pop();
            for(int v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    rem.push(v);
                    taken++;
                }
            }
        }

        return taken == n;
    }
};