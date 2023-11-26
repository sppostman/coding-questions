class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> mapping(256, -1);
        vector<char> targetMapped(256, -1); 

        for(int i=0; i<s.size(); i++){
            if(s[i] == t[i]){
                if(mapping[s[i]] != -1 && mapping[s[i]] != s[i])
                    return false;
                if(targetMapped[t[i]] != -1 && targetMapped[t[i]] != t[i])
                    return false;
                mapping[s[i]] = s[i];
                targetMapped[s[i]] = s[i];
            } else {
                if(mapping[s[i]] != t[i] && mapping[s[i]] != -1)
                    return false;
                if(targetMapped[t[i]] != s[i] && targetMapped[t[i]] != -1)
                    return false;
                mapping[s[i]] = t[i];
                targetMapped[t[i]] = s[i];
            }
        }

        return true;
    }
};