class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> path;
        vector<int> dist;
        int curr = n-1;

        for(int i=0; i<n; i++)
            path.insert(i);

        for(auto q : queries){
            int u = q[0], v = q[1];
            if(path.find(u) != path.end() && path.find(v) != path.end()){
                auto it = path.find(u);
                it++;
                while(it!=path.end() && *it < v){
                    auto nxt = it;
                    nxt++;
                    curr--;
                    path.erase(*it);
                    it = nxt;
                }
            }
            dist.push_back(curr);
        }
        return dist;
    }
};