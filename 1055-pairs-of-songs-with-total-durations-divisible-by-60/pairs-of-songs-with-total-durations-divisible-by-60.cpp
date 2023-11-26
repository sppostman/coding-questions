class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> encountered;
        int pairs = 0;
        // for(int t : time){
        //     if(t%60 == 0){
        //         pairs += encountered[0];
        //     } else {
        //         pairs += encountered[60 - t%60];
        //     }
        //     encountered[t%60]++;
        // }
        for(int t : time){
            pairs += encountered[(60 - t%60)%60];
            encountered[t%60]++;
        }
        return pairs;
    }
};