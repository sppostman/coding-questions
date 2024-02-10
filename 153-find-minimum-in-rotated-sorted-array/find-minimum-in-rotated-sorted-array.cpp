class Solution {
public:
    int findMin(vector<int>& arr) {
        int l=0, r=arr.size()-1, mid;
        int mn = arr[0];

        while(l<=r){
            mid = l+(r-l)/2;

            mn = min(arr[mid], mn);

            if(arr[l] <= arr[r])
                return min(mn, arr[l]);
                
            if(arr[l] <= arr[mid]){
                mn = min(mn, arr[l]);
                l = mid+1;
            }
            else {
                mn = min(mn, arr[mid]);
                r = mid-1;
            }
        }
        
        return mn;
    }
};