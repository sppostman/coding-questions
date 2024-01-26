class Solution {
public:
    int findMin(vector<int>& arr) {
        int l=0,r=arr.size()-1,mid;
        int mn = arr[0];

        while(l<=r){
            int mid = l+(r-l)/2;
            mn = min(arr[mid], mn);

            if(arr[l] <= arr[r]){
                mn = min(arr[l], mn);
                break;
            }

            if(arr[l] <= arr[mid]){
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return mn;
    }
};