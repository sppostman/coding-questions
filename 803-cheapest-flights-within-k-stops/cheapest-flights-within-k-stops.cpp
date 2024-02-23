class Solution {
public:
    int bestroute(int n, vector<pair<int,int>> graph[n], vector<bool> &vis, int node, int dst, int used, int steps){
        if(node == dst)
            return used;
        vis[node] = true;
        int bestRoute = -1;
        for(const auto &[next, cost] : graph[node]){
            if(!vis[next] && steps>=0){
                // printf("%d to %d (%d)\n",node,next, used+cost);
                int routeCost = bestroute(n, graph, vis, next, dst, used+cost, steps-1);
                if(routeCost != -1 && (routeCost<bestRoute || bestRoute==-1))
                    bestRoute = routeCost;
            }
        }
        vis[node] = false;
        return bestRoute;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> graph[n];
        vector<bool> vis(n, false);
        for(auto flight : flights){
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
        // return bestroute(n, graph, vis, src, dst, 0, k);

        queue<pair<int, pair<int,int>>> travel; // {next, {costed,steps}}
        vector<int> dist(n, 1e9);
        dist[src]=0;
        travel.push({src, {0, 0}});
        while(travel.size()){
            const auto [node, weights] = travel.front();
            const auto [costed, steps] = weights;
            travel.pop();

            for(const auto &[next, cost] : graph[node]){
                // printf("%d to %d __ %d (%d)\n",node,next,steps, costed+cost);
                int nextCost = cost+costed;
                if(steps<=k && nextCost < dist[next]){
                    dist[next] = nextCost;
                    travel.push({next, {nextCost, steps+1}});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};