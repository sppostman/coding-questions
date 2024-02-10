class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // idx => 0, 1, 2, 3, 4
        // arr => 2, 3, 4, 7, 11
        // miss=> 1, 1, 1, 3, 6

        int l =0, r=arr.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            int missing = arr[mid]-mid-1;

            if(missing < k){
                l = mid+1;
            } else
                r = mid-1;
        }

        return l+k;
        
    }
};