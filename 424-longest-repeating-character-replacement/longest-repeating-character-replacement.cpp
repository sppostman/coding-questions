class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.size();
        int best = 0;

        vector<int> freq(26, 0);
        int mxFreq=0;

        int i=0, j=0;
        while(j<n){
            int c = s[j]-'A';
            freq[c]++;
            mxFreq = max(mxFreq, freq[c]);

            // while(j-i+1 - mxFreq > k){
            //     char rem = s[i]-'A';
            //     freq[rem]--;
            //     if(freq[rem]+1 == mxFreq){
            //         mxFreq = 0;
            //         for(int k=0; k<26; k++)
            //             mxFreq = max(mxFreq, freq[k]);
            //     }
            //     i++;
            // }
            if(j-i+1 - mxFreq > k){
                char rem = s[i]-'A';
                freq[rem]--;
                // if(freq[rem]+1 == mxFreq){
                //     mxFreq = 0;
                //     for(int k=0; k<26; k++)
                //         mxFreq = max(mxFreq, freq[k]);
                // }
                i++;
            }

            if(j-i+1 - mxFreq <= k)
                best = max(best, j-i+1);
            j++;
        }
        return best;

        // // O(N^2)
        // for(int i=0; i<n; i++){
        //     vector<int> freq(26, 0);
        //     int mxFreq=0;
        //     for(int j=i; j<n; j++){
        //         int c = s[j]-'A';
        //         freq[c]++;
        //         mxFreq = max(freq[c], mxFreq);
        //         if(j-i+1 - mxFreq <= k)
        //             best = max(best, j-i+1);
        //         else
        //             break;
        //     }
        // }
        // return best;
    }
};