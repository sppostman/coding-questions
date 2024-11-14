class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        vector<int> last(256, -1);
        int l=0;
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if(last[c] >= l){
                l = last[c]+1;
            }
            res = max(res, i-l+1);
            last[c] = i;
        }
        return res;
    }
};