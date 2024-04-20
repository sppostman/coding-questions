class Solution {
public:
    int longestSubstring(string s, int k){
        if(k<=1)
            return s.size();
        return lss(s,0,s.size()-1, k);
    }
    int lss(string s, int begin, int end, int k) {
        if(begin > end || k > end-begin+1)
            return 0;

        vector<int> freq(26, 0);
        for(int i=begin; i<=end; i++)
            freq[s[i]-'a']++;
        
        for(int j=begin; j<=end; j++){
            char c = s[j];
            if(freq[c-'a'] < k){
                return max(
                    lss(s, begin, j-1, k),
                    lss(s, j+1, end, k)
                );
            }
        }
        return end-begin+1;
    }
};