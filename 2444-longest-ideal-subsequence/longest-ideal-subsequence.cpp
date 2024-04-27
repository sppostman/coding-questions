class Solution {
public:
    int solve(int i, char prevChar, string &s, int k, vector<vector<int>> &dp){
        if(i==s.size())
            return 0;
        if(dp[i][prevChar-'a'] != -1)
            return dp[i][prevChar-'a'];

        int res = solve(i+1, prevChar, s, k, dp);
        if(prevChar == '{' || abs(s[i] - prevChar) <= k){
            res = max(res, solve(i+1, s[i], s, k, dp) + 1);
        }
        return dp[i][prevChar-'a'] = res;
    }

    int longestIdealString(string s, int k) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(27, -1));
        return solve(0, '{', s, k, dp);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = max(
                    i > 0 ? dp[i-1][j] : 0,
                    j > 0 ? dp[i][j-1] : 0
                );
                if(i>0 && j>0){
                    if(abs(s[j-1] - s[i]) <= k)
                        dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                } else if(s[j]==s[i])
                    dp[i][j] = 1;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }

        return dp[n-1][n-1];


//         vector<int> occured(26, 0);
//         int longest = 0;
//         for(char c : s){
//             int i = c-'a';
//             int currSeq = 0;

//             occured[i]++;

//             for(int j=max(0, i-k); j<=min(25, i+k); j++){
//                 if(occured[j])
//                     printf(" -- take %c => %d\n", j+'a', occured[j]);
//                 currSeq += occured[j];
//             }
// // lkkcg
// // px
//             printf("for %c => %d\n", c, currSeq);
//             longest = max(longest, currSeq);
//         }
//         return longest;
    }
};