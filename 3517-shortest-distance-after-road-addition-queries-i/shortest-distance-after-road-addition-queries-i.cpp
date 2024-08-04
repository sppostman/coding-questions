class Solution {
public:
    int shortestPath(int u, int v, vector<vector<int>> &adj, vector<int> &mindist){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> rem;
        rem.push({ mindist[u], u });

        while(rem.size()){
            int dist = rem.top().first;
            int j = rem.top().second;
            rem.pop();

            // if(j == v)
            //     return dist;
            
            for(int nb : adj[j]){
                if(dist+1 < mindist[nb]){
                    mindist[nb] = min(mindist[nb], dist+1);
                    rem.push({ dist+1, nb });
                }
            }
        }
        return mindist[v];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int> mindist(n, INT_MAX);

        for(int i=0; i<n-1; i++){
            adj[i].push_back(i+1);
            mindist[i] = i;
        }
        
        vector<int> dist;
        for(auto q : queries){
            adj[q[0]].push_back(q[1]);
            dist.push_back(
                shortestPath(q[0], n-1, adj, mindist)
            );
        }
        return dist;
    }
};