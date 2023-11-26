class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> mapping(256, -1);
        vector<char> targetMapped(256, -1); 

        for(int i=0; i<s.size(); i++){
            if(mapping[s[i]] != t[i] && mapping[s[i]] != -1)
                return false;
            if(targetMapped[t[i]] != s[i] && targetMapped[t[i]] != -1)
                return false;
            mapping[s[i]] = t[i];
            targetMapped[t[i]] = s[i];
        }

        return true;
    }
};