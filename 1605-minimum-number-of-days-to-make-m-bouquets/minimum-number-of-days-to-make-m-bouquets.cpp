class Solution {
public:
    bool works(vector<int>& bloomDay, int m, int k, int day){
        int consec = 0;
        int bouquets = 0;
        for(int b : bloomDay){
            if(b-day <= 0){
                consec++;
            } else {
                bouquets += consec / k;
                consec = 0;
                if(bouquets >= m)
                    return true;
            }
        }
        bouquets += consec / k;
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 1;
        int h = *max_element(bloomDay.begin(), bloomDay.end());
        int days=-1;

        while(l <= h){
            int mid = l+(h-l)/2;

            if(works(bloomDay, m, k, mid)){
                h = mid-1;
                days = mid;
            } else
                l = mid+1;
        }
        return days;
    }
};