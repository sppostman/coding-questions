class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       // idx => 0, 1, 2, 3, 4
        // arr => 2, 3, 4, 7, 11
        // miss=> 1, 1, 1, 3, 6
        
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

        return r+1+k;
    }
};