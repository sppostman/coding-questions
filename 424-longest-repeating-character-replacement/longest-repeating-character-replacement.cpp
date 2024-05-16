class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i=0, j=0;
        int maxLen = 0;

        vector<int> freq(26,0);
        int maxFreq = 0;
        while(j<n){
            int c = s[j] - 'A';
            freq[c]++;
            maxFreq = max(maxFreq, freq[c]);

            while(j-i+1 - maxFreq > k){
                freq[s[i]-'A']--;
                i++;
                maxFreq = 0;
                for(int x=0; x<26; x++)
                    maxFreq = max(maxFreq, freq[x]);
            }

            maxLen = max(maxLen, j-i+1);
            j++;
        }

        return maxLen;
    }
};