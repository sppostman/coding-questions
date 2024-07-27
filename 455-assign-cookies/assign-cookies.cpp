class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int i = 0, j = 0;
        while(j < s.size() && i<g.size()){
            if(s[j] >= g[i]){
                i++;
            } 
            j++;
        }
        return i;
    }
};