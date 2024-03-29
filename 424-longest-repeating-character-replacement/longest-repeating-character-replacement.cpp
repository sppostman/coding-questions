class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.size();
        int best = 0;
        for(int i=0; i<n; i++){
            vector<int> freq(26, 0);
            int mxFreq=0;
            for(int j=i; j<n; j++){
                int c = s[j]-'A';
                freq[c]++;
                mxFreq = max(freq[c], mxFreq);
                if(j-i+1 - mxFreq <= k)
                    best = max(best, j-i+1);
                else
                    break;
            }
        }
        return best;
    }
};