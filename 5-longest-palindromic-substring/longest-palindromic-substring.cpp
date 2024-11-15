class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int li = 0, lj = 0;
        for(int i=0; i<n; i++){
            dp[i][i] = true;
            if(i<n-1 && s[i] == s[i+1]){
                dp[i][i+1] = dp[i+1][i] = true;
                li = i;
                lj = i+1;
            }
            if(i>0)     dp[i-1][i] = s[i]==s[i-1];
        }
        for(int k=2; k<n; k++){
            for(int i=0; i+k<n; i++){
                int j = i+k;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    li = i;
                    lj = j;
                } else
                    dp[i][j] = false;
            }
        }
        return s.substr(li, lj-li+1);
    }
};