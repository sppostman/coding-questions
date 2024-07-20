class Solution {
public:
    bool works(vector<int>& piles, int h, int perhour){
        int time = 0;
        for(int b : piles){
            time += (b+perhour-1)/perhour;
            if(time > h)
                return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = r;
        while(l<=r){
            int m = l+(r-l)/2;
            if(works(piles, h, m)){
                r = m-1;
                ans = m;
            } else {
                l = m+1;
            }
        }
        return l;
    }
};