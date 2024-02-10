class Solution {
public:
    bool works(vector<int>& weights, int days, int capacity){
        int rem = capacity;
        for(int w : weights){
            if(rem >= w){
                rem -= w;
            } else {
                days--;
                rem = capacity - w;
                if(rem < 0 || days < 0)
                    return false;
            }
        }
        days -= rem<capacity ? 1 : 0;
        return days >= 0;
    }
    int leastdays(vector<int>& weights){
        int sum = 0;
        for(int w : weights)
            sum += w;
        return sum;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int h = leastdays(weights);
        int m, ans=-1;

        while(l<=h){
            m = l+(h-l)/2;
            if(works(weights, days, m)){
                ans = m;
                h = m-1;
            } else
                l = m+1;
        }
        return ans;
    }
};