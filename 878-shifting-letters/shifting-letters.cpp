class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int shiftCount = 0;
        int n =s.size();
        string res(n, '-');

        for(int i=n-1; i>-1; i--){
            shiftCount += shifts[i];
            shiftCount %= 26;
            // printf("For %c, shift %d => %c\n", s[i], shiftCount, s[i] + shiftCount);
            res[i] = ((s[i]-'a' + shiftCount)%26) + 'a';
        }

        return res;
    }
};