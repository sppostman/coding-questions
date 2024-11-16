class Solution {
public:
    bool same(string &s, int i, string &t){
        for(int k = 0; k<t.size(); k++){
            if(s[i+k] != t[k])
                return false;
        }
        return true;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> works(n+1);
        works[0] = true;
        for(int i=1; i<=n; i++){
            for(auto word : wordDict){
                int st = i-word.size();
                if(st>=0 && works[st] && same(s, st, word)){
                    works[i] = true;
                    break;
                }
            }
        }
        return works[n];
    }
};