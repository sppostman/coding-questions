class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> freq(3, -1);
        int count = 0;

        // aabaabbbc
        for(int i=0; i<n; i++){
            freq[s[i]-'a'] = i;
            int minWindowLeft = min({freq[0], freq[1], freq[2]});
            count += minWindowLeft+1;
        }

        return count;
    }
};