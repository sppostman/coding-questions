class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int zeros=0, ones=0;
        for(int i=0; i<n; i++){
            // zeros += s[i]=='0';
            ones += s[i]=='1';
        }

        // vector<int> zeros(n);
        // vector<int> ones(n);

        // zeros[0] = s[0]=='0';
        // ones[0] = s[0]=='1';;
            
        // for(int i=1; i<n; i++){
        //     zeros[i] = zeros[i-1] + s[i]=='0';
        //     ones[i] = ones[i-1] + s[i]=='1';
        // }

        int maxScore = 0;
        for(int i=0; i<n-1; i++){
            ones -= s[i]=='1';
            zeros += s[i]=='0';
            maxScore = max(maxScore, zeros+ones);
        }

        return maxScore;
    }
};