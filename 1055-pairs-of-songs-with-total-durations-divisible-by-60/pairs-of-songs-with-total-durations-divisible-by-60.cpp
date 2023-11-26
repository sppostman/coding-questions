class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> encountered;
        int pairs = 0;
        for(int t : time){
            if(t%60 == 0){
                pairs += encountered[0];
                encountered[0]++;
            } else {
                printf("Search for %d, ", 60-(t%60));
                if(encountered.find(60 - (t%60)) != encountered.end()){
                    pairs += encountered[60 - t%60];
                    printf("found: %d\n", encountered[60 - t%60]);
                }
                encountered[t%60]++;
            }
        }
        return pairs;
    }
};