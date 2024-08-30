class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tchars(256, 0);
        for(char c : t)
            tchars[c]++;

        int gotten = 0;
        int k = t.size();
        int n = s.size();

        int i=0, j=0, minWindow=INT_MAX, minI=-1;

        while(j<n){
            char c = s[j];
            if(tchars[c] > 0)
                gotten++;
            tchars[c]--;

            while(gotten == k){
                if(j-i+1 < minWindow){
                    minI = i;
                    minWindow = j-i+1;
                }
                tchars[s[i]]++;
                if(tchars[s[i]] > 0)
                    gotten--;
                i++;
            }
            j++;
        }
        return minI == -1 ? "" : s.substr(minI, minWindow);
    }
};