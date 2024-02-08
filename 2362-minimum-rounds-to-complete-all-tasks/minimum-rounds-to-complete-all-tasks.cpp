class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> counts;
        for(int task : tasks)
            counts[task]++;

        int totalrounds=0;
        for(auto &[task, count] : counts){
            if(count == 1)
                return -1;
            totalrounds += ceil((double)count/3.0);
        }
        return totalrounds;
    }
};