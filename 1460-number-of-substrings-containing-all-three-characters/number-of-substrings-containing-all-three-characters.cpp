class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> prev(3, -1);

        int n=s.size();
        int count = 0;

        for(int i=0; i<n; i++){
            int c = s[i]-'a';
            prev[c] = i;
            if(prev[0] != -1 && prev[1] != -1 && prev[2] != -1){
                int minimalWindowLeft = min({ prev[0], prev[1], prev[2]});
                count += minimalWindowLeft+1;
            }
        }
        
        return count;
    }
};