class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counter;
        for(int n : nums)
            counter[n]++;

        priority_queue<pair<int,int>> pq;
        for(auto &[key, count] : counter)
            pq.push({count, key});

        vector<int> result;
        for(int i=0; i<k && pq.size(); i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};