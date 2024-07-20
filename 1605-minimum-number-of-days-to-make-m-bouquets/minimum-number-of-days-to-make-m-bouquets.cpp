class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int day){
        int bouqets = 0;
        int takenFlowers = 0;
        for(int bd : bloomDay){
            if(bd <= day){
                takenFlowers++;
                if(takenFlowers == k){
                    bouqets++;
                    takenFlowers = 0;
                }
            } else {
                takenFlowers = 0;
            }
        }
        return bouqets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = *min_element(bloomDay.begin(), bloomDay.end());

        int mx = *max_element(bloomDay.begin(), bloomDay.end());
        int r = mx;

        int mid;
        while(l<=r){
            mid = l+(r-l)/2;
            if(canMake(bloomDay, m, k, mid)){
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return l > mx ? -1 : l;
    }
};