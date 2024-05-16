class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<bool> present(256, false);

        int i=0, j=0;
        int mxLength = 0;
        while(j<n){
            while(present[s[j]]){
                present[s[i]] = false;
                i++;
            }

            present[s[j]] = true;
            mxLength = max(mxLength, j-i+1);

            j++;
        }

        return mxLength;
    }
};