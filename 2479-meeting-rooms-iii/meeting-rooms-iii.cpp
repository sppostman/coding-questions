class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& givenmeets) {
        vector<vector<int>> meetings = givenmeets;
        sort(meetings.begin(), meetings.end());                
        vector<int> meetsHosted(n, 0);

        // endtime, roomidx
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> busy;

        // roomidx
        priority_queue<int, vector<int>, greater<int>> empty;
        
        for(int i=0; i<n; i++)
            empty.push(i);

        for(auto &meet : meetings){
            int start = meet[0], end=meet[1];
            cout<<start<<", "<<end<<endl;

            while(busy.size() && busy.top().first <= start){
                empty.push(busy.top().second);
                busy.pop();
            }

            if(empty.size() > 0){
                int allotroom = empty.top();
                empty.pop();
                meetsHosted[allotroom]++;
                busy.push({ end, allotroom });
            } else {
                auto latentRoom = busy.top();
                busy.pop();
                meetsHosted[latentRoom.second]++;
                busy.push({ latentRoom.first+end-start, latentRoom.second });
            }
        }

        return max_element(meetsHosted.begin(), meetsHosted.end()) - meetsHosted.begin();
    }
};