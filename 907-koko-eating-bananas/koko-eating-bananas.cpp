class Solution {
public:
    bool works(vector<int>& piles, int k, int hours){
        for(int pile : piles){
            hours -= ceil(pile*1.0/k);
            if(hours<0)
                return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int hours) {
        int l = 1, mid;
        int h = piles[0];
        for(int pile : piles)
            h = max(h, pile);
        
        int bestK = h;

        while(l <= h){
            mid = l+(h-l)/2;

            if(works(piles, mid, hours)){
                bestK = mid;
                h = mid-1;
            } else
                l = mid+1;
        }

        return bestK;
    }
};