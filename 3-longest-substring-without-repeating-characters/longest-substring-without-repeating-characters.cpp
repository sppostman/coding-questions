class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> occurence(256, -1);

        int i=0, j=0;
        int mxLength = 0;
        while(j<n){
            if(occurence[s[j]] >= i)
                i = occurence[s[j]]+1;

            occurence[s[j]] = j;
            mxLength = max(mxLength, j-i+1);

            j++;
        }

        return mxLength;
    }
};