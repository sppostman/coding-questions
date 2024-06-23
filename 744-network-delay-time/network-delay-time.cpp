class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto f : times){
            adj[f[0]].push_back({ f[1], f[2] });
        }

        vector<int> minTime(n, INT_MAX);
        queue<pair<int,int>> rem;
        minTime[k-1] = 0;
        rem.push({ k, 0 });

        int visited = 1;
        
        while(rem.size()){
            auto it = rem.front();
            rem.pop();
            int u = it.first;
            int uTime = it.second;

            for(auto nb : adj[u]){
                int v = nb.first;
                int goTime = nb.second;
                if(minTime[v-1] == INT_MAX)
                    visited++;

                if(uTime+goTime < minTime[v-1]){
                    minTime[v-1] = uTime+goTime;
                    rem.push({ v, minTime[v-1] });
                }
            }
        }
        if(visited < n)
            return -1;
        return *max_element(minTime.begin(), minTime.end());
    }
};