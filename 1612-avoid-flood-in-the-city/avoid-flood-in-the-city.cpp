const int MAX_LAKES = 1e9+1;
class Solution {
public:
    // int clearit(vector<int>& rains){
    //     int l=0, r=rains.size()-1;
    //     int mid;
    //     while(l<=r){
    //         mid = =l+(r-l)/2;
    //         if(rains[mid] <= 0){

    //         }
    //     }
    // }
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        // priority_queue<int> dryslots;
        set<int> drydays;
        unordered_map<int,int> full;

        vector<int> result(n, 1);

        for(int i=0; i<n; i++){
            if(rains[i] == 0){
                drydays.insert(i);
            } else {
                if(full.find(rains[i]) != full.end()){
                    auto dryday = drydays.upper_bound(full[rains[i]]);
                    if(dryday != drydays.end()){
                        result[*dryday] = rains[i];
                        drydays.erase(*dryday);
                    } else {
                        return {};
                    }
                }

                full[rains[i]] = i;
                result[i] = -1;
            }
        }

        return result;
    }
};