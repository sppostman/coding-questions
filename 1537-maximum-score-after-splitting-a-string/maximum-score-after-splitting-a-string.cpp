class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int ones=0;
        for(int i=0; i<n; i++){
            ones += s[i]=='1';
        }

        int zeros=0;
        int maxScore = 0;
        for(int i=0; i<n-1; i++){
            ones -= s[i]=='1';
            zeros += s[i]=='0';
            maxScore = max(maxScore, zeros+ones);
        }

        return maxScore;
    }
};