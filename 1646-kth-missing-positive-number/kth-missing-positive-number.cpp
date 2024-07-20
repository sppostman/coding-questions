class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // 2 3 4 7 11
        //         
        // 11_7
        // l = 11, r = 7+(k-xxxx);

        // 11 -> 6
        // 7 -> 3
        // 7+2
        
        int l=0, r=arr.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;

            int expected = arr[m]-1;

            if(expected - m >= k){
                r = m-1;
            } else {
                l = m+1;
            }
        }

        return l+k;
    }
};