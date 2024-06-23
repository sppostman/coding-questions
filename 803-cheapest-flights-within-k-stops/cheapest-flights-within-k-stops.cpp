class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto f : flights){
            adj[f[0]].push_back({ f[1], f[2] });
        }
        vector<int> minCost(n, INT_MAX);
        queue<pair<int,int>> rem;
        minCost[src] = 0;
        rem.push({ src, 0 });
        
        int stops = 0;
        while(rem.size()){
            if(stops > k){
                return minCost[dst] == INT_MAX ? -1 : minCost[dst];
            }
            stops++;

            int thisLevel = rem.size();
            while(thisLevel--){
                auto it = rem.front();
                rem.pop();
                int u = it.first;
                int uCost = it.second;

                for(auto nb : adj[u]){
                    int v = nb.first;
                    int goCost = nb.second;

                    if(uCost+goCost < minCost[v]){
                        minCost[v] = uCost+goCost;
                        rem.push({ v, minCost[v] });
                        cout<<v<<","<<minCost[v];
                    }
                }
            }
        }
        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};