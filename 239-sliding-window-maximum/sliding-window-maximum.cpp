class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;

        priority_queue<pair<int,int>> pq;
        for(int i=0; i<k; i++){
            pq.push({nums[i], i});
        }
        res.push_back(pq.top().first);

        int i=0, j=k-1;
        while(j<n-1){
            i++;
            while(pq.size() && pq.top().second < i)
                pq.pop();

            j++;
            pq.push({nums[j], j});
            res.push_back(pq.top().first);
        }
        return res;
        

        // int i=0;
        // int mx = nums[0];
        
        // for(int tmp=0; tmp<k; tmp++)
        //     mx = max(mx, nums[tmp]);
        // res.push_back(mx);
        
        // for(int j=k; j<n; j++){
        //     if(mx == nums[i]){
        //         mx = nums[i+1];
        //         for(int tmp=i+1; tmp<j; tmp++)
        //             mx = max(mx, nums[tmp]);
        //     }
        //     i++;
        //     mx = max(mx, nums[j]);
        //     res.push_back(mx);
        // }

        // return res;
    }
};