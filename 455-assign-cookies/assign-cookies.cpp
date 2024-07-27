class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int fulfilled = 0;
        int c = 0;
        for(auto greed : g){
            while(c<s.size() && greed > s[c])
                c++;
            if(c==s.size())
                return fulfilled;
            c++;
            fulfilled++;
        }
        return fulfilled;
    }
};